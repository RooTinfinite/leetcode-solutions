class Solution:
    def minimumCost(self, n: int, highways: List[List[int]], discounts: int) -> int:
        g = collections.defaultdict(list)
        for c1, c2, t in highways:
            g[c1].append((c2, t))
            g[c2].append((c1, t))
        
        cost = {(k, c) : float('inf') for k in range(discounts + 1) for c in range(n)}
        pq = [(0, discounts, 0)]
        while pq:
            toll, discnt, city = heapq.heappop(pq)
            if city == n - 1: return toll
            
            for c, t in g[city]:
                if toll + t < cost[(discnt, c)]:
                    cost[(discnt, c)] = toll + t
                    heapq.heappush(pq, (cost[(discnt, c)], discnt, c))
                if discnt and toll + t // 2 < cost[(discnt - 1, c)]:
                    cost[(discnt - 1, c)] = toll + t // 2
                    heapq.heappush(pq, (cost[(discnt - 1, c)], discnt - 1, c))
        return -1