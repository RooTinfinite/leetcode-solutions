class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left = 0
        charDict = defaultdict(lambda:0)
        result = 0

        for right in range(len(s)):            
            charDict[s[right]] += 1
            
            currLen = right - left + 1
            if currLen - max(charDict.values()) <= k:
                result = max(result, currLen)
            else:
                charDict[s[left]] -= 1
                left += 1

        return result