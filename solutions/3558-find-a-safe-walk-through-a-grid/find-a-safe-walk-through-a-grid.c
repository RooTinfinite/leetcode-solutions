typedef struct {
    int x, y;
} Point;

typedef struct {
    Point* data;
    int head;  // pointing to the first element of the queue
    int tail;  // pointing to the next position after the tail element of the
               // queue
    int capacity;  // queue capacity
} Deque;

Deque* dequeCreate(int capacity) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (Point*)malloc(sizeof(Point) * capacity);
    dq->head = 0;
    dq->tail = 0;
    dq->capacity = capacity;
    return dq;
}

void dequePushFront(Deque* dq, int x, int y) {
    dq->head = (dq->head - 1 + dq->capacity) % dq->capacity;
    dq->data[dq->head].x = x;
    dq->data[dq->head].y = y;
}

void dequePushBack(Deque* dq, int x, int y) {
    dq->data[dq->tail].x = x;
    dq->data[dq->tail].y = y;
    dq->tail = (dq->tail + 1) % dq->capacity;
}

Point dequePopFront(Deque* dq) {
    Point p = dq->data[dq->head];
    dq->head = (dq->head + 1) % dq->capacity;
    return p;
}

bool dequeIsEmpty(Deque* dq) { return dq->head == dq->tail; }

void dequeFree(Deque* dq) {
    free(dq->data);
    free(dq);
}

bool findSafeWalk(int** grid, int gridSize, int* gridColSize, int health) {
    int m = gridSize, n = gridColSize[0];
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int** dis = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dis[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dis[i][j] = INT_MAX;
        }
    }

    Deque* q = dequeCreate(m * n + 1);
    dequePushFront(q, 0, 0);
    dis[0][0] = grid[0][0];

    while (!dequeIsEmpty(q)) {
        Point cur = dequePopFront(q);
        int cx = cur.x;
        int cy = cur.y;
        // the first time it leaves the queue, the shortest distance is
        // guaranteed
        if (cx == m - 1 && cy == n - 1) {
            for (int i = 0; i < m; i++) free(dis[i]);
            free(dis);
            dequeFree(q);
            return true;
        }

        for (int k = 0; k < 4; k++) {
            int nx = cx + dirs[k][0];
            int ny = cy + dirs[k][1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                continue;
            }
            int cost = dis[cx][cy] + grid[nx][ny];
            // pruning: the new distance does not meet health requirements
            if (cost >= health) {
                continue;
            }
            if (cost < dis[nx][ny]) {
                dis[nx][ny] = cost;
                if (grid[nx][ny] == 0) {
                    dequePushFront(q, nx, ny);
                } else {
                    dequePushBack(q, nx, ny);
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        free(dis[i]);
    }
    free(dis);
    dequeFree(q);
    return false;
}