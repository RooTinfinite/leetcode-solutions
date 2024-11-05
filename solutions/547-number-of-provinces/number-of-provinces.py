class UF:
    def __init__(self, n):
        self.p = list(range(n))
        self.height = [1] * n

    def find(self, u):
        if self.p[u] == u:
            return u
        return self.find(self.p[u])

    def merge(self, root1, root2):
        if root1 == root2:
            return
        if self.height[root1] < self.height[root2]:
            root1, root2 = root2, root1
        self.p[root2] = root1
        self.height[root1] = max(self.height[root1], 1 + self.height[root2])

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        uf = UF(n)
        for i in range(n):
            for j in range(i + 1, n):
                if isConnected[i][j] == 1:
                    root1 = uf.find(i)
                    root2 = uf.find(j)
                    uf.merge(root1, root2)
        
        components = set()
        for i in range(n):
            components.add(uf.find(i))
        
        return len(components) 