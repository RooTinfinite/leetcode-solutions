class Solution:
    def wordPatternMatch(self, pattern: str, s: str) -> bool:
        
        def fn(i, k):
            """Return True if pattern[i:] can be mapping to s[k:]"""
            if i == len(pattern): return k == len(s) # boundary condition
            if k == len(s): return i == len(pattern) # boundary condition 
            
            if pattern[i] in mp: 
                if mp[pattern[i]] == s[k:k+len(mp[pattern[i]])] and fn(i+1, k+len(mp[pattern[i]])): return True
                return False
            for kk in range(k+1, len(s)+1): 
                if s[k:kk] not in mp: 
                    mp[pattern[i]] = s[k:kk]
                    mp[s[k:kk]] = pattern[i]
                    if fn(i+1, kk): return True 
                    mp.pop(pattern[i])
                    if pattern[i] != s[k:kk]: mp.pop(s[k:kk])
            return False
        
        mp = {}
        return fn(0, 0)