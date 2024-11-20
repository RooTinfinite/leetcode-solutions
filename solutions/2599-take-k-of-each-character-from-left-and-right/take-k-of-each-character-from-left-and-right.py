class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        freq = Counter(s)
        if freq['a'] < k or freq['b'] < k or freq['c'] < k:
            return -1

        result = len(s)
        left = 0

        for right in range(len(s)):
            freq[s[right]] -= 1      

            while freq[s[right]] < k:
                freq[s[left]] += 1      
                left += 1
            result = min(result, freq['a'] + freq['b'] + freq['c'])
        return result