class Solution:
    def getSmallestString(self, s: str, k: int) -> str:
        n = len(s)
        result = list(s)
        for i in range(n):
            for j in range(26):
                new_char = chr(ord('a') + j)
                diff = min((ord(new_char) - ord(s[i])) % 26 , (ord(s[i]) - ord(new_char)) % 26)
                if diff <= k:
                    result[i] = new_char
                    k -= diff
                    break
        return "".join(result)