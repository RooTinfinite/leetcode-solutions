class MyCircularQueue {
    queue: number[];
    tailIndex: number;
    capacity: number;

    constructor(capacity: number) {
        this.queue = new Array(capacity);
        this.tailIndex = 0;
        this.capacity = capacity;
    }

    enQueue(value: number): void {
        this.queue[this.tailIndex] = value;
        this.tailIndex = (this.tailIndex + 1) % this.capacity;
    }

    get(index: number): number {
        return this.queue[index % this.capacity];
    }
}

function calculateMinimumHP(dungeon: number[][]): number {
    const rows = dungeon.length;
    const cols = dungeon[0].length;
    const dp = new MyCircularQueue(cols);

    const getMinHealth = (
        currCell: number,
        nextRow: number,
        nextCol: number,
    ): number => {
        if (nextRow < 0 || nextCol < 0) return Infinity;
        const index = cols * nextRow + nextCol;
        const nextCell = dp.get(index);
        return Math.max(1, nextCell - currCell);
    };

    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            const currCell = dungeon[rows - row - 1][cols - col - 1];
            const rightHealth = getMinHealth(currCell, row, col - 1);
            const downHealth = getMinHealth(currCell, row - 1, col);
            const nextHealth = Math.min(rightHealth, downHealth);

            let minHealth;
            if (nextHealth !== Infinity) {
                minHealth = nextHealth;
            } else {
                minHealth = currCell >= 0 ? 1 : 1 - currCell;
            }

            dp.enQueue(minHealth);
        }
    }

    return dp.get(cols - 1);
}