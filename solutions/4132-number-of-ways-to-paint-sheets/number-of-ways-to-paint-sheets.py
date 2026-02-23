from bisect import bisect_left
from typing import List

class Solution:
    def numberOfWays(self, n: int, limit: List[int]) -> int:
        MOD = 10**9 + 7
        limit.sort()
        m = len(limit)

        points = {1, n}
        for x in limit:
            if 1 < x + 1 < n:
                points.add(x + 1)
            if 1 < n - x < n:
                points.add(n - x)
        
        sorted_points = sorted(list(points))

        def get_count(val):
            return m - bisect_left(limit, val)

        res = 0
        for i in range(len(sorted_points) - 1):
            start = sorted_points[i]
            end = sorted_points[i+1]
            length = end - start
            
            k = start
            cnt_left = get_count(k)
            cnt_right = get_count(n - k)
            cnt_both = get_count(max(k, n - k))
            
            ways = (cnt_left * cnt_right - cnt_both) % MOD
            res = (res + ways * length) % MOD

        return res % MOD