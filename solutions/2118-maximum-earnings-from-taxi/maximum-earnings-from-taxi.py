class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        rideStartAt = defaultdict(list)
        for s, e, t in rides:
            rideStartAt[s].append([e, e - s + t])  # [end, dollar]

        dp = [0] * (n + 1)
        for i in range(n - 1, 0, -1):
            for e, d in rideStartAt[i]:
                dp[i] = max(dp[i], dp[e] + d)
            dp[i] = max(dp[i], dp[i + 1])

        return dp[1]