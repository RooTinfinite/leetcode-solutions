class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        
        # Find the longest non-decreasing prefix
        left_end = 0
        while left_end + 1 < n and arr[left_end] <= arr[left_end + 1]:
            left_end += 1
            
        # If array is already non-decreasing, return 0
        if left_end == n - 1:
            return 0
            
        # Find the longest non-decreasing suffix
        right_start = n - 1
        while right_start > left_end and arr[right_start - 1] <= arr[right_start]:
            right_start -= 1
            
        # Initial answer is minimum of:
        # 1. Remove everything after left_end
        # 2. Remove everything before right_start
        min_length = min(n - left_end - 1, right_start)
        
        # Try to merge prefix and suffix
        left = 0
        right = right_start
        while left <= left_end and right < n:
            if arr[right] >= arr[left]:
                # Found a valid merge point
                # Update minimum length by removing elements between left and right
                min_length = min(min_length, right - left - 1)
                left += 1
            else:
                right += 1
                
        return min_length