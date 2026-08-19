class Solution:
    # O(n^2)
    def elevatorRequests(self, _: int, start: int, a: list[list[int]]) -> int:
        n = len(a)
        a = sorted(a, key = itemgetter(1)) + [[inf, inf]] # sort by height + add padding
        t, h = zip(*a)
        
        # ........ ]i ......... j[ .......
        # fulfilled] unfulfilled [fulfilled

        # dp[i][j][left | right]
        dp = [[[inf, inf] for _ in range(n + 1)] for _ in range(n + 1)]

        # base case
        dp[1][n - 1][0] = max(t[0]    , abs(start - h[0]))
        dp[0][n - 2][1] = max(t[n - 1], abs(start - h[n - 1]))

        # push DP
        for gap in range(n - 2, -1, -1):
            for i,j in zip(range(n), range(gap, n)):
                dp[i + 1][j][0] = min(dp[i + 1][j][0], max(dp[i][j][0] + abs(h[i] - h[i - 1]), t[i])) # l -> l
                dp[i][j - 1][1] = min(dp[i][j - 1][1], max(dp[i][j][0] + abs(h[j] - h[i - 1]), t[j])) # l -> r
                dp[i][j - 1][1] = min(dp[i][j - 1][1], max(dp[i][j][1] + abs(h[j] - h[j + 1]), t[j])) # r -> r
                dp[i + 1][j][0] = min(dp[i + 1][j][0], max(dp[i][j][1] + abs(h[i] - h[j + 1]), t[i])) # r -> l

        return min(dp[i][i - 1][b] for i in range(n + 1) for b in range(2))