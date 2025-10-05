class Solution:
    def hasSpecialSubstring(self, s: str, k: int) -> bool:
        n = len(s)

        l = 0
        char = s[0]
        for r in range(n):
            if  char != s[r]:
                char = s[r]
                l = r

            if r - l + 1 > k:
                l += 1
            
            if r-l+1 == k and (l == 0 or s[l-1] != char) and (r == n-1 or s[r+1] != char):
                return True
        return False
