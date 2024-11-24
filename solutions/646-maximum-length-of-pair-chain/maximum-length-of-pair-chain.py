class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        def isFollow(p1, p2):
            return p1[1] < p2[0]
        
        n = len(pairs)
        pairs.sort()
        dp = [1] * n
        ans = 1
        for i in range(1, n):
            for j in range(i):
                if isFollow(pairs[j], pairs[i]) and dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
            ans = max(ans, dp[i])
        return ans