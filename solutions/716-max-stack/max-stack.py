class MaxStack:

    def __init__(self):
        self.maxH = []
        self.clean_elements = set() 
        self.stack = []
        self.id = 0
    
    def clean_stk_or_heap(self):
        while self.stack and self.stack[-1][1] in self.clean_elements:
            self.clean_elements.remove(self.stack[-1][1])
            self.stack.pop()
        while self.maxH and self.maxH[0][1] in self.clean_elements:
            self.clean_elements.remove(self.maxH[0][1])
            heapq.heappop(self.maxH)


    def push(self, x: int) -> None:
        self.stack.append((x, self.id))
        heapq.heappush(self.maxH, (-x, self.id))
        self.id -= 1

    def pop(self) -> int:
        if len(self.stack) == 0:
            raise Exception("Nope")
        x, x_id = self.stack.pop()
        self.clean_elements.add(x_id)
        self.clean_stk_or_heap()
        return x

    def top(self) -> int:
        return self.stack[-1][0]

    def peekMax(self) -> int:
        return -self.maxH[0][0]

    def popMax(self) -> int:
        x, x_id = heapq.heappop(self.maxH)
        self.clean_elements.add(x_id)
        self.clean_stk_or_heap()
        return -x
