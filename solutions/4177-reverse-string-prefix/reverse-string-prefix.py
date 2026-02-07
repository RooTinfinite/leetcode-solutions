class Solution:
    def reversePrefix(self, s: str, k: int) -> str:
        s = list(s)
        
        for i in range(k // 2):
            s[i], s[k - 1 - i] = s[k - 1 - i], s[i]
        
        return "".join(s)