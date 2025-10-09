class Solution:
    def digit_sum(self, n: int) -> int:
        total = 0
        while n > 0:
            total += n % 10
            n //= 10
        return total

    def smallestIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if i == self.digit_sum(nums[i]):
                return i
        return -1