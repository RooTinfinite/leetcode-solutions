import heapq
class MaxStack:

    def __init__(self):
        self.stack = []
        self.heap = []
        self.removed = set()
        self.counter = 0
        

    def push(self, x: int) -> None:
        self.stack.append((x, self.counter))
        heapq.heappush(self.heap, (-x, -self.counter))
        self.counter += 1


    def pop(self) -> int:
        while self.stack and self.stack[-1][1] in self.removed:
            self.stack.pop()
        val, key = self.stack.pop()
        self.removed.add(key)
        return val
        

    def top(self) -> int:
        while self.stack and self.stack[-1][1] in self.removed:
            self.stack.pop()
        return self.stack[-1][0]
        

    def peekMax(self) -> int:
        while self.heap and -self.heap[0][1] in self.removed:
            heapq.heappop(self.heap)
        return -self.heap[0][0]
        

    def popMax(self) -> int:
        while self.heap and -self.heap[0][1] in self.removed:
            heapq.heappop(self.heap)
        val, key = heapq.heappop(self.heap)
        self.removed.add(-key)
        return -val