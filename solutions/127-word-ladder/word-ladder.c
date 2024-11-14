// Defining a structure for storing string list
typedef struct StringList {
    char *string;
    struct StringList *next;
} StringList;

// Hash table structure for storing transformations
typedef struct HashTable {
    char *key;
    StringList *list;
    UT_hash_handle hh;
} HashTable;

// Node structure for BFS queue
typedef struct Node {
    char *word;
    int level;
} Node;

// Queue node structure
typedef struct QueueNode {
    Node *node;
    struct QueueNode *next;
} QueueNode;

// Queue structure
typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

// Function prototypes
Queue *createQueue();
void enqueue(Queue *q, Node *node);
Node *dequeue(Queue *q);
int isEmpty(Queue *q);
void addTransformation(HashTable **table, char *key, char *value);
StringList *findList(HashTable *table, char *key);

// Create a new queue
Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Add a node to the queue
void enqueue(Queue *q, Node *node) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->node = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

// Remove a node from the queue
Node *dequeue(Queue *q) {
    if (q->front == NULL) return NULL;

    QueueNode *temp = q->front;
    Node *node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->size--;
    return node;
}

// Check if the queue is empty
int isEmpty(Queue *q) { return q->front == NULL; }

// Add a transformation to the hash table
void addTransformation(HashTable **table, char *key, char *value) {
    HashTable *s;
    HASH_FIND_STR(*table, key, s);
    if (s == NULL) {
        s = (HashTable *)malloc(sizeof(HashTable));
        s->key = strdup(key);
        s->list = NULL;
        HASH_ADD_KEYPTR(hh, *table, s->key, strlen(s->key), s);
    }
    StringList *new_string = (StringList *)malloc(sizeof(StringList));
    new_string->string = strdup(value);
    new_string->next = s->list;
    s->list = new_string;
}

// Find list from the hash table
StringList *findList(HashTable *table, char *key) {
    HashTable *s;
    HASH_FIND_STR(table, key, s);
    return (s == NULL) ? NULL : s->list;
}

// Ladder length function (BFS)
int ladderLength(char *beginWord, char *endWord, char **wordList,
                 int wordListSize) {
    int L = strlen(beginWord);

    // Create hash table for transformations
    HashTable *allComboDict = NULL;
    for (int j = 0; j < wordListSize; j++) {
        char *word = wordList[j];
        for (int i = 0; i < L; i++) {
            char newWord[100];
            snprintf(newWord, sizeof(newWord), "%.*s*%s", i, word,
                     word + i + 1);
            addTransformation(&allComboDict, newWord, word);
        }
    }

    // Initialize the BFS queue
    Queue *Q = createQueue();
    Node *startNode = (Node *)malloc(sizeof(Node));
    startNode->word = strdup(beginWord);
    startNode->level = 1;
    enqueue(Q, startNode);

    // Visited hash table
    HashTable *visited = NULL;
    addTransformation(&visited, beginWord, "");

    while (!isEmpty(Q)) {
        Node *node = dequeue(Q);
        char *word = node->word;
        int level = node->level;
        for (int i = 0; i < L; i++) {
            char newWord[100];
            snprintf(newWord, sizeof(newWord), "%.*s*%s", i, word,
                     word + i + 1);
            StringList *transformations = findList(allComboDict, newWord);
            while (transformations != NULL) {
                char *adjacentWord = transformations->string;
                if (strcmp(adjacentWord, endWord) == 0) {
                    return level + 1;
                }
                if (findList(visited, adjacentWord) == NULL) {
                    addTransformation(&visited, adjacentWord, "");
                    Node *newNode = (Node *)malloc(sizeof(Node));
                    newNode->word = strdup(adjacentWord);
                    newNode->level = level + 1;
                    enqueue(Q, newNode);
                }
                transformations = transformations->next;
            }
        }
        free(node->word);
        free(node);
    }

    return 0;
}