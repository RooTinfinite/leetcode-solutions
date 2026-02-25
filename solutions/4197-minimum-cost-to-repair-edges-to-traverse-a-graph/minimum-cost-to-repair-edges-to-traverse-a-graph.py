class Solution:
    def minCost(self, n: int, edges: List[List[int]], k: int) -> int:
        def test(mid):
            stk = deque([0])
            vis = [1] + [0] * (n - 1)
            ct = 1
            while stk:
                stk.append(None)
                while stk[0] != None:
                    cur = stk.popleft()
                    for nxt, w in gr[cur]:
                        if w <= mid and not vis[nxt]:
                            if nxt == n - 1:
                                return True
                            vis[nxt] = 1
                            stk.append(nxt)
                if ct == k:
                    return False
                ct += 1
                stk.popleft()
            return False

        gr = [[] for _ in range(n)]
        for a, b, w in edges:
            gr[a].append((b, w))
            gr[b].append((a, w))

        l = 1
        ma = max(e[2] for e in edges)
        r = ma + 1
        while l < r:
            mid = (l + r) // 2
            if test(mid):
                r = mid
            else:
                l = mid + 1
        return r if r <= ma else -1