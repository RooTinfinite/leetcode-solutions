class Solution:
    def countValidSubstrings(self, s: str) -> int:

        n, ptr, abc = len(s), 0, 0
        ans = (n * n + n) // 2
        abc = s.find('abc')

        while abc != -1:
            abc+= 1
            ans-= (abc - ptr) * (n - 1 - abc)
            abc, ptr = s.find('abc', ptr), abc

        return ans