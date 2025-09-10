class Solution:
    def countTexts(self, S: str) -> int:
        
        mod = 10 ** 9 + 7
        
        dp = [0] * (len(S) + 1)
        dp[0] = 1
        for i in range(1, len(S) + 1):
            dp[i] = dp[i - 1]
            if i - 2 >= 0 and S[i-1] == S[i-2]:
                dp[i] += dp[i - 2]
            if i - 3 >= 0 and S[i-1] == S[i-2] and S[i-1] == S[i-3]:
                dp[i] += dp[i - 3]
                
            if S[i-1] in {"7", "9"}:
                if i - 4 >= 0 and S[i-1] == S[i-2] and S[i-1] == S[i-3] and S[i-1] == S[i-4]:
                    dp[i] += dp[i - 4]
            dp[i] %= mod
            
        return dp[-1] % mod