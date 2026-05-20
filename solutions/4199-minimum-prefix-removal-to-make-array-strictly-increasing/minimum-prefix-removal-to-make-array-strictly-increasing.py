class Solution:
    def minimumPrefixLength(self, nums: List[int]) -> int:
        count1=0
        if len(nums)==0:
            return 0
        if len(nums)==1:
            return 0
        i=len(nums)-1     
        while( nums[i]> nums[i-1] and i!=0):
                i=i-1
        return i
        
        
            
            
        