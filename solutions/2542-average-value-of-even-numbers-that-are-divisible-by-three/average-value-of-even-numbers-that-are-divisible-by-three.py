class Solution:
    def averageValue(self, nums: List[int]) -> int:
        sum = 0 
        count = 0
        for n in nums:
            if n%2==0 and n%3==0:
                sum +=n 
                count +=1
        if count==0:
            return 0 
        return sum//count 