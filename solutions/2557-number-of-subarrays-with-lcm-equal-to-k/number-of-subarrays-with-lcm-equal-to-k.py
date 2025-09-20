import math
class Solution:
    def subarrayLCM(self, nums: List[int], k: int) -> int:
        def gcd(a,b):
            return math.gcd(a,b)
        def lcm(n1,n2):
            return (n1*n2)//gcd(n1,n2)
        n=len(nums)
        ans=0
        for i in range(n):
            lcmi=nums[i]
            for j in range(i,n):
                lcmi=lcm(lcmi,nums[j])
                if(lcmi==k):
                    ans+=1
        return ans