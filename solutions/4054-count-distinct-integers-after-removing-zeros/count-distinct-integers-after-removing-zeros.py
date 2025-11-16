class Solution:
    def countDistinct(self, n: int) -> int:
        s = str(n)
        length = len(s)
        ans = 0
        p = [1] * (length + 1)
        for i in range(1, length + 1):
            p[i] = p[i-1] * 9
        for l in range(1, length):
            ans += p[l]
        for i in range(length):
            d = ord(s[i]) - ord('0')
            if d == 0:
                return ans
            ans += (d - 1) * p[length - i - 1]
        res = ans + 1
        return res
