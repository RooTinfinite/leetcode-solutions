class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        freqs = [0] * 3
        n = len(s)
        
        for c in s:
            freqs[ord(c) - ord('a')] += 1
        
        i = 0
        j = 0
        if freqs[0] < k or freqs[1] < k or freqs[2] < k:
            return -1
        
        for j in range(n):
            freqs[ord(s[j]) - ord('a')] -= 1
            
            if freqs[0] < k or freqs[1] < k or freqs[2] < k:
                freqs[ord(s[i]) - ord('a')] += 1
                i += 1
            

        return n - (j - i + 1)
                
        
            