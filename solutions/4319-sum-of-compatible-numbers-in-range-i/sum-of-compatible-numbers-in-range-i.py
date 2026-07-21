class Solution:
    def sumOfGoodIntegers(self, n: int, k: int) -> int:
        result = 0

        for x in range(max(1, n - k), n + k + 1):
            if (n & x) == 0:
                result += x

        return result