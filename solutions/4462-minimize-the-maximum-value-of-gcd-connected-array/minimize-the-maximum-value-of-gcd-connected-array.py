class Solution:
    def minimumMaxValue(self, n: int, index: int, value: int) -> int:
        if value == 1:
            return -1
        if value % 2 == 0:
            p = 2
        else:
            p = value
            i = 3
            while i * i <= value:
                if value % i == 0:
                    p = i
                    break
                i += 2
        l = index
        r = n - index - 1
        if l > (value - p) // 2:
            return -1
        if r == 0:
            return value
        return value + p + 2 * (r - 1)