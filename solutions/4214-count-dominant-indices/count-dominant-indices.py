class Solution:
    def dominantIndices(self, nums: List[int]) -> int:
        n=len(nums)
        runningavg=[0]*n
        count=0
        runningavg[n-1]=nums[n-1]
        for i in range(len(nums)-2,-1,-1):
            runningavg[i]=runningavg[i+1]+nums[i];
        for i in range(len(nums)-1):
            avg=runningavg[i+1]/(n-i-1)
            if(nums[i]>avg):
                count+=1
        return count