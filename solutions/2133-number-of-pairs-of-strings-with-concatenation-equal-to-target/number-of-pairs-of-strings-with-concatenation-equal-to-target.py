class Solution(object):
    def numOfPairs(self, nums, target):
        """
        :type nums: List[str]
        :type target: str
        :rtype: int
        """
        count = 0
        freq = Counter(nums)
        
        for i in range(len(nums)):
            prefix = nums[i]
            if target.startswith(prefix):
                suffix = target[len(prefix):]
                if suffix in freq:
                    count += freq[suffix]
                    if prefix == suffix:
                        count -= 1  
        
        return count
  