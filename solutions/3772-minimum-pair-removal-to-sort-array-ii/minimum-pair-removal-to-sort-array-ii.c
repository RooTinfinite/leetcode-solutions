#define MIN_QUEUE_SIZE 4096

typedef struct Node {
    long long value;
    int left;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(long long value, int left) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = left;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

typedef struct QueueItem {
    Node* first;
    Node* second;
    long long cost;
    int firstLeft;
    int secondLeft;
} QueueItem;

typedef struct Element {
    QueueItem item;
} Element;

typedef bool (*CompareFunc)(const void*, const void*);

static bool itemLess(const void* a, const void* b) {
    const Element* e1 = (const Element*)a;
    const Element* e2 = (const Element*)b;
    const QueueItem* item1 = &e1->item;
    const QueueItem* item2 = &e2->item;
    if (item1->cost != item2->cost) {
        return item1->cost > item2->cost;
    }
    return item1->firstLeft > item2->firstLeft;
}

static void swap(Element* arr, int i, int j) {
    Element t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

typedef struct PriorityQueue {
    Element* arr;
    int capacity;
    int queueSize;
    CompareFunc lessFunc;
} PriorityQueue;

PriorityQueue* createPriorityQueue(CompareFunc cmpFunc) {
    PriorityQueue* obj = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    obj->capacity = MIN_QUEUE_SIZE;
    obj->arr = (Element*)malloc(sizeof(Element) * obj->capacity);
    obj->queueSize = 0;
    obj->lessFunc = cmpFunc;
    return obj;
}

static void down(Element* arr, int size, int i, CompareFunc cmpFunc) {
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < size && cmpFunc(&arr[smallest], &arr[left])) {
            smallest = left;
        }
        if (right < size && cmpFunc(&arr[smallest], &arr[right])) {
            smallest = right;
        }
        if (smallest == i) {
            break;
        }
        swap(arr, i, smallest);
        i = smallest;
    }
}

void enQueue(PriorityQueue* obj, const QueueItem* item) {
    if (obj->queueSize == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = (Element*)realloc(obj->arr, sizeof(Element) * obj->capacity);
    }

    obj->arr[obj->queueSize].item = *item;

    int i = obj->queueSize;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (!obj->lessFunc(&obj->arr[parent], &obj->arr[i])) {
            break;
        }
        swap(obj->arr, i, parent);
        i = parent;
    }

    obj->queueSize++;
}

QueueItem* deQueue(PriorityQueue* obj) {
    if (obj->queueSize == 0) {
        return NULL;
    }

    swap(obj->arr, 0, obj->queueSize - 1);
    QueueItem* result = &obj->arr[obj->queueSize - 1].item;
    obj->queueSize--;
    if (obj->queueSize > 0) {
        down(obj->arr, obj->queueSize, 0, obj->lessFunc);
    }

    return result;
}

QueueItem* front(const PriorityQueue* obj) {
    if (obj->queueSize == 0) {
        return NULL;
    }
    return &obj->arr[0].item;
}

bool isEmpty(const PriorityQueue* obj) { return obj->queueSize == 0; }

int size(const PriorityQueue* obj) { return obj->queueSize; }

void freeQueue(PriorityQueue* obj) {
    free(obj->arr);
    free(obj);
}

int minimumPairRemoval(int* nums, int numsSize) {
    PriorityQueue* pq = createPriorityQueue(itemLess);
    bool* merged = (bool*)calloc(numsSize, sizeof(bool));
    int decreaseCount = 0;
    int count = 0;

    Node** nodes = (Node**)malloc(sizeof(Node*) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        nodes[i] = createNode(nums[i], i);
        if (i > 0) {
            nodes[i - 1]->next = nodes[i];
            nodes[i]->prev = nodes[i - 1];
        }
    }

    for (int i = 1; i < numsSize; i++) {
        QueueItem item;
        item.first = nodes[i - 1];
        item.second = nodes[i];
        item.cost = item.first->value + item.second->value;
        item.firstLeft = item.first->left;
        item.secondLeft = item.second->left;
        enQueue(pq, &item);
        if (nums[i - 1] > nums[i]) {
            decreaseCount++;
        }
    }

    while (decreaseCount > 0 && !isEmpty(pq)) {
        QueueItem* itemPtr = deQueue(pq);
        if (!itemPtr) {
            break;
        }
        QueueItem item = *itemPtr;

        if (merged[item.firstLeft] || merged[item.secondLeft]) {
            continue;
        }

        Node* first = item.first;
        Node* second = item.second;
        long long cost = item.cost;

        if (!first || !second) {
            continue;
        }
        if (first->next != second) {
            continue;
        }
        if (first->value + second->value != cost) {
            continue;
        }

        count++;

        if (first->value > second->value) {
            decreaseCount--;
        }

        Node* prevNode = first->prev;
        Node* nextNode = second->next;

        first->next = nextNode;
        if (nextNode) {
            nextNode->prev = first;
        }
        second->prev = NULL;
        second->next = NULL;

        if (prevNode) {
            if (prevNode->value > first->value && prevNode->value <= cost) {
                decreaseCount--;
            }
            if (prevNode->value <= first->value && prevNode->value > cost) {
                decreaseCount++;
            }
            QueueItem newItem;
            newItem.first = prevNode;
            newItem.second = first;
            newItem.cost = prevNode->value + cost;
            newItem.firstLeft = prevNode->left;
            newItem.secondLeft = first->left;
            enQueue(pq, &newItem);
        }

        if (nextNode) {
            if (second->value > nextNode->value && cost <= nextNode->value) {
                decreaseCount--;
            }
            if (second->value <= nextNode->value && cost > nextNode->value) {
                decreaseCount++;
            }
            QueueItem newItem;
            newItem.first = first;
            newItem.second = nextNode;
            newItem.cost = cost + nextNode->value;
            newItem.firstLeft = first->left;
            newItem.secondLeft = nextNode->left;
            enQueue(pq, &newItem);
        }

        first->value = cost;
        merged[second->left] = true;
    }

    for (int i = 0; i < numsSize; i++) {
        if (!merged[i]) {
            free(nodes[i]);
        }
    }
    free(nodes);
    free(merged);
    freeQueue(pq);

    return count;
}