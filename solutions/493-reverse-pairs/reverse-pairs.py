class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def recursiveFunction(lowerIndex = 0, upperIndex = len(nums) - 1):
            
            if lowerIndex >= upperIndex:
                return 0
            
            midIndex = (lowerIndex + upperIndex) // 2
            count = recursiveFunction(lowerIndex, midIndex) + recursiveFunction(midIndex + 1, upperIndex)
            
            index_i = lowerIndex
            for rightNumber in nums[midIndex + 1: upperIndex + 1]:
                while index_i <= midIndex and nums[index_i] <= rightNumber * 2:
                    index_i += 1
                count += midIndex + 1 - index_i
                if index_i > midIndex:
                    break
            
            nums[lowerIndex: upperIndex + 1] = sorted(nums[lowerIndex: upperIndex + 1])
			
            return count
        
        return recursiveFunction()