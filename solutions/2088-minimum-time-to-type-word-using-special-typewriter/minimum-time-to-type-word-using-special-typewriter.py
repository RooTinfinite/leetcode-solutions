class Solution:
    def minTimeToType(self, word: str) -> int:
        ans = len(word)
        prev = "a"
        for ch in word: 
            val = (ord(ch) - ord(prev)) % 26 
            ans += min(val, 26 - val)
            prev = ch
        return ans 