class Solution:
    def interactionCosts(self, n: int, edges: List[List[int]], group: List[int]) -> int:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        tcount = Counter(group)
        self.ans = 0

        def dfs(u, p):
            ucount = Counter()
            ucount[group[u]] = 1
            for v in adj[u]:
                if v == p:
                    continue

                vcount = dfs(v, u)
                for g, c in vcount.items():
                    self.ans += c * (tcount[g] - c)

                if len(vcount) > len(ucount):
                    ucount, vcount = vcount, ucount
                ucount.update(vcount)

            return ucount

        dfs(0, -1)
        return self.ans