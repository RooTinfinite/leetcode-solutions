class Allocator:

    class Node:
        def __init__(self, index: int, size: int, id: int):
            self.index = index
            self.size = size
            self.id = id # -1 = free
            self.prev = None
            self.next = None

    def __init__(self, n: int):
        self.head = self.Node(0, n, -1)
        self.used = defaultdict(list) # id : [Node]

    def allocate(self, size: int, mID: int) -> int:
        node = self.head
        while node:
            if node.id == -1:
                if node.size >= size:
                    node.id = mID
                    if node.size > size: 
                        nextNode = self.Node(node.index + size, node.size - size, -1)
                        node.size = size
                        nextNext = node.next
                        node.next = nextNode
                        nextNode.prev = node
                        nextNode.next = nextNext
                        if nextNext:
                            nextNext.prev = nextNode
                    self.used[mID].append(node)
                    return node.index
            node = node.next
        return -1

    def freeMemory(self, mID: int) -> int:
        if mID not in self.used:
            return 0
        ret = 0
        for node in self.used[mID]:
            if node.id != mID:
                continue
            ret += node.size
            prevN = node.prev
            nextN = node.next
            node.id = -1
            if nextN and nextN.id == -1:
                # combine with next node
                node.size += nextN.size
                node.next = nextN.next
                if nextN.next:
                    nextN.next.prev = node
            if prevN and prevN.id == -1:
                # combine with prev node
                prevN.size += node.size
                prevN.next = node.next
                if node.next:
                    node.next.prev = prevN
            
        del self.used[mID]
        return ret
        
        


# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.freeMemory(mID)