class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        averages = [-1] * len(nums)
        # When a single element is considered then its average will be the number itself only.
        if k == 0:
            return nums

        window_size = 2 * k + 1
        n = len(nums)

        # Any index will not have 'k' elements in it's left and right.
        if window_size > n:
            return averages

        # First get the sum of first window of the 'nums' arrray.
        window_sum = sum(nums[:window_size])
        averages[k] = window_sum // window_size

        # Iterate on rest indices which have at least 'k' elements 
        # on its left and right sides.
        for i in range(window_size, n):
            # We remove the discarded element and add the new element to get current window sum.
            # 'i' is the index of new inserted element, and
            # 'i - (window size)' is the index of the last removed element.
            window_sum = window_sum - nums[i - window_size] + nums[i]
            averages[i - k] = window_sum // window_size

        return averages