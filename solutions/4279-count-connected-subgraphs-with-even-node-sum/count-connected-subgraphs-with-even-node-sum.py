class Solution:
    class DSU:
        def __init__(self, n):
            self.par = list(range(n))
            self.rank = [0]*n

        def find(self, x):
            if self.par[x] != x:
                self.par[x] = self.find(self.par[x])
            return self.par[x]

        def union(self, a, b):
            pa = self.find(a)
            pb = self.find(b)
            if pa == pb:
                return
            if self.rank[pa] < self.rank[pb]:
                self.par[pa] = pb
            elif self.rank[pa] > self.rank[pb]:
                self.par[pb] = pa
            else:
                self.par[pb] = pa
                self.rank[pa] += 1

    def dfs(self, i, n, curr):
        self.list.append(curr[:])
        for idx in range(i, n):
            curr.append(idx)
            self.dfs(idx+1, n, curr)
            curr.pop()

    def evenSumSubgraphs(self, nums, edges):
        self.list = []
        self.dfs(0, len(nums), [])

        count = 0

        for sub in self.list:
            if len(sub) == 0:
                continue

            s = sum(nums[node] for node in sub)
            if s % 2 != 0:
                continue

            st = set(sub)
            d = self.DSU(len(nums))

            for u, v in edges:
                if u in st and v in st:
                    d.union(u, v)

            parent = set()
            for x in sub:
                parent.add(d.find(x))

            if len(parent) == 1:
                count += 1

        return count