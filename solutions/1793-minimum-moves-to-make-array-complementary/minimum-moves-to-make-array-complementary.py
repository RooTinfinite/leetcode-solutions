class Solution(object):
    def minMoves(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """
        n = len(nums)
        delta = [0] * (2 * limit + 2)  

        for i in range(n // 2):
            a = nums[i]
            b = nums[n - 1 - i]
            low = 1 + min(a, b)
            high = limit + max(a, b)
            total = a + b
            
            delta[2] += 2
            delta[low] -= 1
            delta[total] -= 1
            delta[total + 1] += 1
            delta[high + 1] += 1

        min_moves = float('inf')
        current = 0
        for s in range(2, 2 * limit + 1):
            current += delta[s]
            min_moves = min(min_moves, current)

        return min_moves