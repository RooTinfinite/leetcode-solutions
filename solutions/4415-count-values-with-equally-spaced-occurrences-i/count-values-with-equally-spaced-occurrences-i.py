class Solution:
    def countSpecialIntegers(self, nums):
        # Intuition: go left to right, skip values that don't occur exactly 3 times
        # then check for an equally spaced triple with increasing distance
        n = len(nums)
        r = 0
        freq = [0] * 100
        for c in nums:
            freq[c - 1] += 1
        for i in range(n):
            c = nums[i]
            if freq[c - 1] != 3:
                continue
            freq[c - 1] = -1
            distance = 1
            while i + (distance * 2) < n:
                if nums[i + distance] == c and nums[i + (distance * 2)] == c:
                    r += 1
                    break
                distance += 1
        return r