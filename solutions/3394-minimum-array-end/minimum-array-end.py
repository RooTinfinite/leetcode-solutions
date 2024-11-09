class Solution:
    def minEnd(self, n: int, x: int) -> int:
        if n == 1:
            return x
        one_count = x.bit_count()
        k = len(bin(x)) - 2
        max_ = 2 ** k - 1
        if one_count == k:
            size = 1
        else:
            size = 2 ** (k - one_count)
        if floor((n - 1)/ size) > 0:
            a = floor((n -1) / size) << k
        else:
            a = 0
        result = a
        left = (n - 1)% size
        x = bin(x)[2:]
        t = ""

        left = bin(left)[2:]
        limit = len(left)
        i = limit - 1
        print(left, result)
        print(x)
        for k in x[::-1]:
            print("k", k, t)
            if k == "1":
                t = "1" + t
            elif i >= 0:
                if left[i] == "1":
                    t = "1" + t
                else:
                    t = "0" + t
                i -= 1
            else:
                t = "0" + t
        result += int(t, 2)
        return result
       