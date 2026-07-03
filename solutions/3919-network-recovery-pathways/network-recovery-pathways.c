typedef struct {
    int v;
    int w;
} Edge;

typedef struct {
    Edge* edges;
    int size;
    int capacity;
} AdjList;

typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

void freeQueue(Queue* q) {
    free(q->data);
    free(q);
}

bool isEmpty(Queue* q) { return q->size == 0; }

void enqueue(Queue* q, int value) {
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(Queue* q) {
    int value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return value;
}

void initAdjList(AdjList* list, int capacity) {
    list->edges = (Edge*)malloc(capacity * sizeof(Edge));
    list->size = 0;
    list->capacity = capacity;
}

void freeAdjList(AdjList* list) { free(list->edges); }

void addEdge(AdjList* list, int v, int w) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->edges =
            (Edge*)realloc(list->edges, list->capacity * sizeof(Edge));
    }
    list->edges[list->size].v = v;
    list->edges[list->size].w = w;
    list->size++;
}

bool check(int mid, long long k, AdjList* g, int* deg, int n) {
    long long* dp = (long long*)malloc(n * sizeof(long long));
    int* cdeg = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        dp[i] = LLONG_MAX / 2;
        cdeg[i] = deg[i];
    }

    dp[0] = 0;
    Queue* q = createQueue(n);
    enqueue(q, 0);

    while (!isEmpty(q)) {
        int u = dequeue(q);

        if (u == n - 1) {
            bool result = dp[u] <= k;
            free(dp);
            free(cdeg);
            freeQueue(q);
            return result;
        }

        for (int i = 0; i < g[u].size; i++) {
            int v = g[u].edges[i].v;
            int w = g[u].edges[i].w;

            if (w >= mid) {
                long long newDist = dp[u] + w;
                if (newDist < dp[v]) {
                    dp[v] = newDist;
                }
            }

            cdeg[v]--;
            if (cdeg[v] == 0) {
                enqueue(q, v);
            }
        }
    }

    free(dp);
    free(cdeg);
    freeQueue(q);
    return false;
}

int findMaxPathScore(int** edges, int edgesSize, int* edgesColSize,
                     bool* online, int onlineSize, long long k) {
    int n = onlineSize;
    AdjList* g = (AdjList*)malloc(n * sizeof(AdjList));
    for (int i = 0; i < n; i++) {
        initAdjList(&g[i], 4);
    }
    int* deg = (int*)calloc(n, sizeof(int));
    int l = INT_MAX, r = 0;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (!online[u] || !online[v]) {
            continue;
        }

        addEdge(&g[u], v, w);
        deg[v]++;
        l = fmin(l, w);
        r = fmax(r, w);
    }

    // Delete unreachable nodes
    Queue* q = createQueue(n);
    for (int i = 1; i < n; i++) {
        if (deg[i] == 0) {
            enqueue(q, i);
        }
    }

    while (!isEmpty(q)) {
        int u = dequeue(q);

        for (int i = 0; i < g[u].size; i++) {
            int v = g[u].edges[i].v;
            deg[v]--;
            if (deg[v] == 0 && v != 0) {
                enqueue(q, v);
            }
        }
    }
    freeQueue(q);

    if (!check(l, k, g, deg, n)) {
        for (int i = 0; i < n; i++) {
            freeAdjList(&g[i]);
        }
        free(g);
        free(deg);
        return -1;
    }

    // 二分查找
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid, k, g, deg, n)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        freeAdjList(&g[i]);
    }
    free(g);
    free(deg);

    return r;
}