class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        freq = [0] * 3
        n = len(s)
        
        for c in s:
            freq[ord(c) - ord('a')] += 1
        
        if any(f < k for f in freq):
            return -1
        
        curr = [0] * 3
        max_len = 0
        left = 0
        
        for right in range(n):
            curr[ord(s[right]) - ord('a')] += 1
            
            while left <= right and any(curr[i] > freq[i] - k for i in range(3)):
                curr[ord(s[left]) - ord('a')] -= 1
                left += 1
            
            max_len = max(max_len, right - left + 1)
        
        return n - max_len