#define MAX_INT 2147483647

typedef struct MyCircularQueue {
    int capacity;
    int tailIndex;
    int* queue;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int capacity) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->queue = (int*)malloc(sizeof(int) * capacity);
    obj->tailIndex = 0;
    obj->capacity = capacity;
    return obj;
}

void myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    obj->queue[obj->tailIndex] = value;
    obj->tailIndex = (obj->tailIndex + 1) % obj->capacity;
}

int myCircularQueueGet(MyCircularQueue* obj, int index) {
    return obj->queue[index % obj->capacity];
}

int getMinHealth(int currCell, int nextRow, int nextCol, int rows, int cols,
                 MyCircularQueue* dp) {
    if (nextRow < 0 || nextCol < 0) return MAX_INT;

    int index = cols * nextRow + nextCol;
    int nextCell = myCircularQueueGet(dp, index);
    // hero needs at least 1 point to survive
    return (1 > nextCell - currCell) ? 1 : nextCell - currCell;
}

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    int rows = dungeonSize;
    int cols = (*dungeonColSize);
    MyCircularQueue* dp = myCircularQueueCreate(cols);

    int currCell, rightHealth, downHealth, nextHealth, minHealth;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            currCell = dungeon[rows - row - 1][cols - col - 1];

            rightHealth = getMinHealth(currCell, row, col - 1, rows, cols, dp);
            downHealth = getMinHealth(currCell, row - 1, col, rows, cols, dp);
            nextHealth = (rightHealth < downHealth) ? rightHealth : downHealth;

            if (nextHealth != MAX_INT) {
                minHealth = nextHealth;
            } else {
                minHealth = (currCell >= 0) ? 1 : 1 - currCell;
            }
            myCircularQueueEnQueue(dp, minHealth);
        }
    }

    // retrieve the last element in the queue
    return myCircularQueueGet(dp, cols - 1);
}