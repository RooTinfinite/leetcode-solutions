class Solution:
    def sumScores(self, s: str) -> int:
        n = len(s)
        dp, ans = [0] * n , [1] * n 
        i, j = 1, 0 
        while i < n:
            if s[i] == s[j]:
                ans[i] += ans[j]
                dp[i] = j + 1
                i += 1
                j += 1
            else:
                if j:
                    j = dp[j - 1]
                else:
                    i += 1
        return sum(ans)
        