import heapq

class MaxStack:

    def __init__(self):
        self.soft_deleted = set()
        self.max_heap = []
        self.recency_stack = []
        self.next_id = 0
        
    def push(self, x: int) -> None:
        heapq.heappush(self.max_heap, (-x, self.next_id))
        self.recency_stack.append((x, self.next_id))
        self.next_id -= 1

    def _clean_up(self):
        while self.recency_stack and self.recency_stack[-1][1] in self.soft_deleted:
            self.soft_deleted.remove(self.recency_stack.pop()[1])
        while self.max_heap and self.max_heap[0][1] in self.soft_deleted:
            self.soft_deleted.remove(heapq.heappop(self.max_heap)[1])
    
    def pop(self) -> int:
        entry_to_return = self.recency_stack.pop()
        self.soft_deleted.add(entry_to_return[1])
        self._clean_up()
        return entry_to_return[0]
        
    def top(self) -> int:
        return self.recency_stack[-1][0]

    def peekMax(self) -> int:
        return -self.max_heap[0][0]
        
    def popMax(self) -> int:
        value, time = heapq.heappop(self.max_heap)
        self.soft_deleted.add(time)
        self._clean_up()
        return value * -1