class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        # workerTimes[i] * (n+1)*n/2
        def get_h(threshold):
            # find height such as: h ^ 2 + h <= threshold
            left = 0
            right = threshold
            res = 0
            while left <= right:
                mid = (left+right)//2
                if mid ** 2 + mid <= threshold:
                    res = mid
                    left = mid + 1
                else:
                    right = mid - 1
            return res

        # binary search
        def is_valid(time):
            total_height = 0
            threshold = time * 2
            for worker in workerTimes:
                # find height such as: h ^ 2 + h <= threshold
                height = get_h(threshold/worker)
                total_height += height
            return total_height >= mountainHeight
        
        left, right= 0, ceil(max(workerTimes) * mountainHeight * (mountainHeight + 1) /2)
        # Right is the maximum time that slowest worker take to destroy the whole mountain by only himself
        res = right
        while left <= right:
            mid = (left+right)//2
            if is_valid(mid):
                res = mid
                right = mid - 1
            else:
                left = mid + 1
        return res