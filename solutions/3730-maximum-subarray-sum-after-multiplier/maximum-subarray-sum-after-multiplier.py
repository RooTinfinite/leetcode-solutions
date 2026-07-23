class Solution:
    inf = int(1e18)

    def div(self, x, k):
        if x >= 0:
            return x // k
        return -((-x) // k)

    def op(self, x, k, flag):
        if flag:
            return x * k
        return self.div(x, k)

    def f(self, v, k, flag):
        n = len(v)
        dp1 = [0] * n
        dp2 = [0] * n
        dp3 = [0] * n

        dp1[0] = v[0]
        dp2[0] = self.op(v[0], k, flag)
        dp3[0] = -self.inf

        for i in range(1, n):
            val = self.op(v[i], k, flag)
            dp1[i] = max(v[i], dp1[i - 1] + v[i])
            dp2[i] = max(val, dp1[i - 1] + val, dp2[i - 1] + val)
            dp3[i] = max(dp2[i - 1] + v[i], dp3[i - 1] + v[i], dp2[i])

        ans = -self.inf
        for i in range(n):
            ans = max(ans, dp1[i], dp2[i], dp3[i])
        return ans

    def maxSubarraySum(self, v, k):
        return max(self.f(v, k, 0), self.f(v, k, 1))