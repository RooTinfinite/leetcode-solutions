class Solution:
    def maxBalancedSubarray(self, nums: List[int]) -> int:
        hmap={}
        xor=0
        eveodd=0
        maxi=0
        hmap["0!0"]=-1
        for i in range(len(nums)):
            xor^=nums[i]
            if (nums[i]&1)==1:
                eveodd+=1
            else:
                eveodd-=1
            curr=str(xor)+"!"+str(eveodd)
            if curr in hmap:
                maxi=max(maxi,i-hmap.get(curr))
            else:
                hmap[curr]=i
        return maxi