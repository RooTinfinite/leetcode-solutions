class Solution:
    def digitRange(self, num: int) -> int:
        if num == 0:
            return 0

        mx = 0
        mn = 9

        while num > 0:
            digit = num % 10
            mx = max(mx, digit)
            mn = min(mn, digit)
            num //= 10

        return mx - mn

    def maxDigitRange(self, nums: List[int]) -> int:
        maxRange = -1

        for num in nums:
            maxRange = max(maxRange, self.digitRange(num))

        total = 0

        for num in nums:
            if self.digitRange(num) == maxRange:
                total += num

        return total