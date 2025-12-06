public class MyCircularQueue {
    protected int capacity;
    protected int tailIndex;
    public int[] queue;

    public MyCircularQueue(int capacity) {
        this.queue = new int[capacity];
        this.tailIndex = 0;
        this.capacity = capacity;
    }

    public void EnQueue(int value) {
        this.queue[this.tailIndex] = value;
        this.tailIndex = (this.tailIndex + 1) % this.capacity;
    }

    public int Get(int index) {
        return this.queue[index % this.capacity];
    }
}

public class Solution {
    int inf = int.MaxValue;
    MyCircularQueue dp;
    int rows, cols;

    public int GetMinHealth(int currCell, int nextRow, int nextCol) {
        if (nextRow < 0 || nextCol < 0)
            return inf;

        int index = cols * nextRow + nextCol;
        int nextCell = this.dp.Get(index);
        return Math.Max(1, nextCell - currCell);
    }

    public int CalculateMinimumHP(int[][] dungeon) {
        this.rows = dungeon.Length;
        this.cols = dungeon[0].Length;
        this.dp = new MyCircularQueue(this.cols);

        int currCell, rightHealth, downHealth, nextHealth, minHealth;
        for (int row = 0; row < this.rows; ++row) {
            for (int col = 0; col < this.cols; ++col) {
                currCell = dungeon[rows - row - 1][cols - col - 1];

                rightHealth = GetMinHealth(currCell, row, col - 1);
                downHealth = GetMinHealth(currCell, row - 1, col);
                nextHealth = Math.Min(rightHealth, downHealth);

                if (nextHealth != inf) {
                    minHealth = nextHealth;
                } else {
                    minHealth = currCell >= 0 ? 1 : 1 - currCell;
                }

                this.dp.EnQueue(minHealth);
            }
        }

        return this.dp.Get(this.cols - 1);
    }
}