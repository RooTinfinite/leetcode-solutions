class MyCircularQueue:
    def __init__(self, capacity: int) -> None:
        """
        Set the size of the queue to be k.
        """
        self.queue = [0] * capacity
        self.tailIndex = 0
        self.capacity = capacity

    def enQueue(self, value: int) -> None:
        """
        Insert an element into the circular queue.
        """
        self.queue[self.tailIndex] = value
        self.tailIndex = (self.tailIndex + 1) % self.capacity

    def get(self, index: int) -> int:
        return self.queue[index % self.capacity]


class Solution(object):
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        rows, cols = len(dungeon), len(dungeon[0])
        # Use a circular queue to keep a sliding window of DP values
        dp = MyCircularQueue(cols)

        def get_min_health(currCell: int, nextRow: int, nextCol: int) -> int:
            if nextRow < 0 or nextCol < 0:
                return float("inf")
            index = cols * nextRow + nextCol
            nextCell = dp.get(index)
            # hero needs at least 1 point to survive
            return max(1, nextCell - currCell)

        for row in range(rows):
            for col in range(cols):
                # iterate the grid in the reversed order
                currCell = dungeon[rows - row - 1][cols - col - 1]

                right_health = get_min_health(currCell, row, col - 1)
                down_health = get_min_health(currCell, row - 1, col)
                next_health = min(right_health, down_health)

                if next_health != float("inf"):
                    min_health = next_health
                else:
                    min_health = 1 if currCell >= 0 else (1 - currCell)

                dp.enQueue(min_health)
        # return the last element in the queue
        return dp.get(cols - 1)