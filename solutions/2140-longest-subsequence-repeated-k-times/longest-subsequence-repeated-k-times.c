typedef struct {
    char* str;
    int len;
} QueueNode;

typedef struct {
    QueueNode* data;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (QueueNode*)malloc(capacity * sizeof(QueueNode));
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue* q, char* str, int len) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear].str = strdup(str);
    q->data[q->rear].len = len;
    q->size++;
}

QueueNode dequeue(Queue* q) {
    if (q->size == 0) {
        QueueNode empty = {NULL, 0};
        return empty;
    }
    QueueNode item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

bool isKRepeatedSubsequence(const char* s, const char* t, int k) {
    int pos = 0, matched = 0;
    int m = strlen(t);
    for (int i = 0; s[i]; i++) {
        if (s[i] == t[pos]) {
            pos++;
            if (pos == m) {
                pos = 0;
                matched++;
                if (matched == k) {
                    return true;
                }
            }
        }
    }
    return false;
}

char* longestSubsequenceRepeatedK(char* s, int k) {
    int freq[26] = {0};
    for (int i = 0; s[i]; i++) {
        freq[s[i] - 'a']++;
    }
    char candidate[26];
    int candidateSize = 0;
    for (int i = 25; i >= 0; i--) {
        if (freq[i] >= k) {
            candidate[candidateSize++] = 'a' + i;
        }
    }

    Queue* q = createQueue(10000);
    for (int i = 0; i < candidateSize; i++) {
        char str[2] = {candidate[i], '\0'};
        enqueue(q, str, 1);
    }
    char* ans = strdup("");
    while (q->size > 0) {
        QueueNode curr = dequeue(q);
        if (curr.len > strlen(ans)) {
            free(ans);
            ans = strdup(curr.str);
        }
        // generate the next candidate string
        for (int i = 0; i < candidateSize; i++) {
            char* next = (char*)malloc(curr.len + 2);
            strcpy(next, curr.str);
            next[curr.len] = candidate[i];
            next[curr.len + 1] = '\0';
            if (isKRepeatedSubsequence(s, next, k)) {
                enqueue(q, next, curr.len + 1);
            } else {
                free(next);
            }
        }
        free(curr.str);
    }

    free(q->data);
    free(q);
    return ans;
}