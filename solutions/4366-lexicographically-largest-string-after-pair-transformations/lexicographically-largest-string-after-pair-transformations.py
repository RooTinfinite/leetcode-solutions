class Solution:
    def largestString(self, nums):
        convert = [1] * 26
        base = 1

        for i in range(26):
            convert[i] = base
            base *= 2

        res = []

        for n in nums:
            cur = []

            while n > 0:
                i = 25

                while convert[i] > n:
                    i -= 1

                cur.append(chr(ord('a') + i))
                n -= convert[i]

            res.append("".join(cur))

        return res