class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        if k == 0:
            return 1
        shortest = len(nums) + 1
        count = [0] * 32
        val = 0
        start = 0
        
        for i in range(len(nums)):
            num = nums[i]
            val |= num
            ibit = 0
            while num:
                count[ibit] += num & 1
                num >>= 1
                ibit += 1
                
            while val >= k and start < len(nums):
                shortest = min(shortest, i - start + 1)
                num = nums[start]
                start += 1
                ibit = 0
                while num:
                    count[ibit] -= num & 1
                    if count[ibit] == 0:
                        val &= ~(1 << ibit)
                    num >>= 1
                    ibit += 1
                    
        return -1 if shortest == len(nums) + 1 else shortest