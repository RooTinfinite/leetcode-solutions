class Solution:
    def goodIndices(self, s: str) -> List[int]:

        n, ans = len(s), []

        for i in range(n):
            num = str(i)
            m = len(num) - 1

            if s[i - m: i+1] == num:
                ans.append(i)

        return ans    