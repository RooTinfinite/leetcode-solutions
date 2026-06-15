class Solution:
    def reverseSubarrays(self, nums: list[int], k: int) -> list[int]:
        div = len(nums)//k
        return sum([nums[i*div:i*div+div][::-1] for i in range(k)],[]) if k > 1 else nums[::-1]