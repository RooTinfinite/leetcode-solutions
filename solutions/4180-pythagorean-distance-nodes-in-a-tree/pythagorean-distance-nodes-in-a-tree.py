import collections

class Solution:
    def specialNodes(self, n: int, edges: List[List[int]], x: int, y: int, z: int) -> int:
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        
        def bfs(s):
            d = [-1] * n
            d[s] = 0
            q = collections.deque([s])
            while q:
                u = q.popleft()
                for v in g[u]:
                    if d[v] == -1:
                        d[v] = d[u] + 1
                        q.append(v)
            return d

        dx, dy, dz = bfs(x), bfs(y), bfs(z)
        
        ans = 0
        for i in range(n):
            a, b, c = dx[i], dy[i], dz[i]
            m = max(a, b, c)
            if a*a + b*b + c*c == 2 * m*m:
                ans += 1
        return ans