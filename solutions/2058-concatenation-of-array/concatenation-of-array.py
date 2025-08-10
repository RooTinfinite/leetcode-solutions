class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        result = []
        for num in nums:
            result.append(num)  # Add each element from nums
        for num in nums:
            result.append(num)  # Add each element again
        return result