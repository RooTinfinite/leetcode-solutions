class Disjoint:
    def __init__(self, size):
        self.size = [1] * size
        self.parent = [i for i in range(size)]
        self.count  = size
    
    def find(self, x):
        if self.parent[x] == x:
            return x
        else:
            self.parent[x] = self.find(self.parent[x])
            return self.parent[x]
        
    def add(self, x, y):
        px = self.find(x)
        py = self.find(y)
        if px == py:
            return
        if self.size[px] < self.size[py]:
            self.parent[px] = py
            self.size[py] += self.size[px]
        else:
            self.parent[py] = px
            self.size[px] += self.size[py] 
        self.count -= 1

class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        wires = len(connections)

        if wires < n-1:
            return -1
        
        dj = Disjoint(n)

        for x, y in connections:
            dj.add(x,y)
        
        # sets = set(dj.find(i) for i in range(n))
        
        if wires >= n-1:
            return dj.count -1

        return -1 

        