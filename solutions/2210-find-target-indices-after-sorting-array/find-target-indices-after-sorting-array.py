class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        cnt1 = 0  # Number of elements less than target
        cnt2 = 0  # Number of elements equal to target
        for num in nums:
            if num < target:
                cnt1 += 1
            elif num == target:
                cnt2 += 1
        res = list(range(cnt1, cnt1 + cnt2))  # Array of indices
        return res