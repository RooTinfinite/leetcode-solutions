class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        
        # 1.Find the rightmost point where array becomes non-ascending
        right = n - 1
        while right > 0 and arr[right - 1] <= arr[right]:
            right -= 1
            
        # 2.If array is already sorted in ascending order
        if right == 0:
            return 0
            
        # 3.Initial minimum length is from start to right pointer
        min_length = right
        
        # Check each element from left side
        for left in range(n):
            # Break if left sequence becomes non-ascending
            if left > 0 and arr[left - 1] > arr[left]:
                break
                
            # Find the first element from right that's >= arr[left]
            while right < n and arr[left] > arr[right]:
                right += 1
                
            # Update minimum length of subarray to be removed
            current_length = right - left - 1
            min_length = min(min_length, current_length)
            
        return min_length