class Solution:
    def balancedStringSplit(self, s: str) -> int:
        k = 0
        ans = 0
        for i in range(len(s)):
            if s[i] == "R":
                k -= 1
                if k == 0:
                    ans += 1
            elif s[i] == "L":
                k += 1
                if k == 0:
                    ans += 1

        return ans