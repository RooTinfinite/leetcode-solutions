class Solution:
    def maxEarnings(self, meetings: List[List[int]]) -> int:
        a = sorted(meetings)
        n = len(a)
        NEG = -(10**18) // 4
        dp = [[[-1, -1], [-1, -1]] for _ in range(n)]

        def lower_bound(x):
            lo, hi = 0, n
            while lo < hi:
                mid = (lo + hi) // 2
                if a[mid][0] < x:
                    lo = mid + 1
                else:
                    hi = mid
            return lo

        def memo(i, is_start, take):
            if i >= n:
                if take:
                    return NEG
                return 0

            if dp[i][is_start][take] != -1:
                return dp[i][is_start][take]

            res = memo(i + 1, is_start, take)
            if take and is_start and i < n - 1:
                res += (a[i + 1][0] - a[i][0])

            idx = lower_bound(a[i][1])

            if idx < n:
                res = max(res, a[i][2] + (a[idx][0] - a[i][1]) + memo(idx, 1, 1))

            res = max(res, a[i][2] + memo(idx, 1, 0))

            dp[i][is_start][take] = res
            return res

        return memo(0, 0, 0)