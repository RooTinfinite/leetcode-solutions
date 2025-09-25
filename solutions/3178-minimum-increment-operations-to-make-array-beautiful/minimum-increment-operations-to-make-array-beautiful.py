class Solution:
    def __init__(self):
        self.dp = [-1] * 100001

    def solve(self, i, v, n):
        if i >= n:
            return 0
        if self.dp[i] != -1:
            return self.dp[i]
        a = v[i] + self.solve(i + 1, v, n)
        b = v[i] + self.solve(i + 2, v, n)
        c = v[i] + self.solve(i + 3, v, n)
        self.dp[i] = min(a, min(b, c))
        return self.dp[i]

    def minIncrementOperations(self, v, k):
        n = len(v)
        for i in range(n):
            v[i] = max(k - v[i], 0)
        self.dp = [-1] * 100001
        ans = self.solve(0, v, n)
        ans = min(ans, self.solve(1, v, n))
        ans = min(ans, self.solve(2, v, n))
        return ans