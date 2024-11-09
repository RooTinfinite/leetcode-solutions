class Solution:
    def maxProfit(self, nums: List[int]) -> int:
        min_pro = float('inf')
        max_pro = 0
        for num in nums:
            min_pro = min(num, min_pro)
            max_pro = max(max_pro, num - min_pro)
        return max_pro