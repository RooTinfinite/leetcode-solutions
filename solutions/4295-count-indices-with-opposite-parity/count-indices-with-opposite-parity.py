class Solution:
    def countOppositeParity(self, nums: list[int]) -> list[int]:
        n = len(nums)
        odd = 0
        even = 0

        result = [0] * n

        for i in range(n - 1, -1, -1):
            if nums[i] % 2 == 1:  # odd
                result[i] = even
                odd += 1
            else:  # even
                result[i] = odd
                even += 1

        return result