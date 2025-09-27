class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        ans = ii = 0 
        freq = Counter()
        for i, ch in enumerate(s): 
            freq[ch] += 1
            while freq[ch] == 3: 
                freq[s[ii]] -= 1
                ii += 1
            ans = max(ans, i-ii+1)
        return ans 