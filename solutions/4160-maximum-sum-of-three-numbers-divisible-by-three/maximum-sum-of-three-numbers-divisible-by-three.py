class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        rem=[[],[],[]]
        for i in nums:
            rem[i%3].append(i)
        res=0
        print(rem)
        if(len(rem[0])>2):
            res=sum(rem[0][:3])
        if(rem[0] and rem[1] and rem[2]):
            res=max(res,rem[0][0]+rem[1][0]+rem[2][0])
        if(len(rem[1])>2):
            res=max(res,sum(rem[1][:3]))
        if(len(rem[2])>2):
            res=max(res,sum(rem[2][:3]))
        return res
            