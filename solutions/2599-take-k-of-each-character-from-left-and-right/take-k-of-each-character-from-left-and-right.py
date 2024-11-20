class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        cnt = [0] * 3
        n = len(s)
        
        for c in s:
            cnt[ord(c) - ord('a')] += 1
        
        l = 0
        r = 0
        
        if cnt[0] < k or cnt[1] < k or cnt[2] < k:
            return -1
        
        for r in range(n):
            cnt[ord(s[r]) - ord('a')] -= 1
            
            if cnt[0] < k or cnt[1] < k or cnt[2] < k:
                cnt[ord(s[l]) - ord('a')] += 1
                l += 1
        
        return n - (r - l + 1)