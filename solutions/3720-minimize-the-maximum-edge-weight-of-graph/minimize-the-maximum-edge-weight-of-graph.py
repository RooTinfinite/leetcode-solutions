class Solution:
    def minMaxWeight(self, n: int, edges: List[List[int]], threshold: int) -> int:

        def dp(mx_wgt: int, end: int, seen: List)-> int:

            seen[end] = res = 1

            for beg, wgt  in graph[end]:
                if seen[beg]: continue
                if wgt <= mx_wgt:
                    res+= dp(mx_wgt, beg, seen)
 
            return res


        graph = [[] for _ in range(n)]
        for beg, end, wgt in edges:
            graph[end].append((beg, wgt))

        _, _, wgts = zip(*edges)
        wgt_lim = max(wgts) + 1
        left, rght = 1, wgt_lim
        
        while left < rght:

            mid = (left + 2 * rght) // 3
            if dp(mid, 0, [0] * n) == n: rght = mid
            else: left = mid + 1

        return left if left < wgt_lim else -1