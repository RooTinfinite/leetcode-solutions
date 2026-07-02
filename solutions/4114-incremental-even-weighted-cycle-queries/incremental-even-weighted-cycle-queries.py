class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.parity = [0] * n
        self.rank = [1] * n

    def find(self, x):
        if self.parent[x] != x:
            original_parent = self.parent[x]
            root = self.find(original_parent)
            
            # Accumulate the parity from the original parent
            self.parity[x] ^= self.parity[original_parent]
            self.parent[x] = root
            
        return self.parent[x]

    def join(self, x, y, w):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX == rootY:
            return

        # Union by rank
        if self.rank[rootX] > self.rank[rootY]:
            self.rank[rootX] += self.rank[rootY]
            self.parent[rootY] = rootX
            self.parity[rootY] = self.parity[y] ^ w ^ self.parity[x]
        else:
            self.rank[rootY] += self.rank[rootX]
            self.parent[rootX] = rootY
            self.parity[rootX] = self.parity[x] ^ w ^ self.parity[y]

    def get_parity(self, x):
        return self.parity[x]


class Solution:
    def numberOfEdgesAdded(self, n: int, edges: list[list[int]]) -> int:
        graph = DSU(n)
        ans = 0

        for x, y, w in edges:
            rootX = graph.find(x)
            rootY = graph.find(y)

            # If they share the same root, a cycle is formed
            if rootX == rootY:
                pathSumFromX = graph.get_parity(x)
                pathSumFromY = graph.get_parity(y)

                # Check if the cycle parity is even (XOR sum is 0)
                if (pathSumFromX ^ pathSumFromY ^ w) == 0:
                    ans += 1
            # If different roots, no cycle is formed, just join them
            else:
                ans += 1
                graph.join(x, y, w)

        return ans