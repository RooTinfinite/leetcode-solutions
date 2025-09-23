class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        if len(s) == 1:
            return 1
        
        l, r, ans, cnt = 0, 1, 0, 0
        
        while r < len(s):
            cnt += (s[r] == s[r-1])
            
            while l <= r and cnt > 1:
                cnt -= (s[l] == s[l+1])
                l += 1
                
            ans = max(ans, r - l + 1)
            r += 1
            
        return ans