class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        seen = set()
        l = 0
        total = 0
        max_sum = 0

        for r in range(len(nums)):
            while nums[r] in seen:
                seen.remove(nums[l])
                total -= nums[l]
                l += 1
            # Add current element
            seen.add(nums[r])
            total += nums[r]
            max_sum = max(max_sum, total)
        return max_sum


        # O(n^2) solution
        # sol = []
        # l = 0
        # r = 1
        # while r <= len(nums):  
        #     if len(nums[l:r]) == len(set(nums[l:r])):
        #         r += 1
        #     else:
        #         sol.append(sum(nums[l:r-1]))
        #         l += 1
        # sol.append(sum(nums[l:r]))
        # return max(sol)


        