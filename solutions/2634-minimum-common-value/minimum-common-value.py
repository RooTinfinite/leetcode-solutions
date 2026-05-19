class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:

        def binary_search(target, nums):
            left = 0
            right = len(nums) - 1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] > target:
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    return True
            return False 
        
        # Binary search should be done on the larger array
        # If nums1 is longer, call getCommon with the arrays swapped
        if len(nums1) > len(nums2): 
            return self.getCommon(nums2, nums1)

        # Search for each element of nums1 in nums2
        # Return the first common element found
        for num in nums1:
            if binary_search(num, nums2):
                return num

        # Return -1 if there are no common elements
        return -1