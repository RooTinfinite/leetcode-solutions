class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        cnt = Counter(s)
        
        if cnt['a'] < k or cnt['b'] < k or cnt['c'] < k:
            return -1
        
        min_len = len(s)
        l = 0
        
        for r in range(len(s)):
            cnt[s[r]] -= 1
            
            while cnt[s[r]] < k:
                cnt[s[l]] += 1
                l += 1
                
            min_len = min(min_len, cnt['a'] + cnt['b'] + cnt['c'])
            
        return min_len