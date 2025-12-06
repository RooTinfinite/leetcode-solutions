class MyCircularQueue {
    protected int capacity;
    protected int tailIndex;
    public int[] queue;

    public MyCircularQueue(int capacity) {
        this.queue = new int[capacity];
        this.tailIndex = 0;
        this.capacity = capacity;
    }

    public void enQueue(int value) {
        this.queue[this.tailIndex] = value;
        this.tailIndex = (this.tailIndex + 1) % this.capacity;
    }

    public int get(int index) {
        return this.queue[index % this.capacity];
    }
}

class Solution {
    int inf = Integer.MAX_VALUE;
    MyCircularQueue dp;
    int rows, cols;

    public int getMinHealth(int currCell, int nextRow, int nextCol) {
        if (nextRow < 0 || nextCol < 0) return inf;

        int index = cols * nextRow + nextCol;
        int nextCell = this.dp.get(index);
        // hero needs at least 1 point to survive
        return Math.max(1, nextCell - currCell);
    }

    public int calculateMinimumHP(int[][] dungeon) {
        this.rows = dungeon.length;
        this.cols = dungeon[0].length;
        this.dp = new MyCircularQueue(this.cols);

        int currCell, rightHealth, downHealth, nextHealth, minHealth;
        for (int row = 0; row < this.rows; ++row) {
            for (int col = 0; col < this.cols; ++col) {
                currCell = dungeon[rows - row - 1][cols - col - 1];

                rightHealth = getMinHealth(currCell, row, col - 1);
                downHealth = getMinHealth(currCell, row - 1, col);
                nextHealth = Math.min(rightHealth, downHealth);

                if (nextHealth != inf) {
                    minHealth = nextHealth;
                } else {
                    minHealth = currCell >= 0 ? 1 : 1 - currCell;
                }
                this.dp.enQueue(minHealth);
            }
        }

        // retrieve the last element in the queue
        return this.dp.get(this.cols - 1);
    }
}