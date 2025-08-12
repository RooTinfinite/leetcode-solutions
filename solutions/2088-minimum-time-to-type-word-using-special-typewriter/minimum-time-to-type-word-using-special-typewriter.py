class Solution:
    def minTimeToType(self, word: str) -> int:
        ans = len(word)
        prev = 'a'
        for ch in word:
            diff = abs(ord(ch) - ord(prev))
            ans += min(diff, 26 - diff)
            prev = ch
        return ans