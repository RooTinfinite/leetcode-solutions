class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)

        maxq, minq = deque(), deque()
        
        result = l = r = 0
        while r < n:
            while maxq and nums[maxq[-1]] <= nums[r]:
                maxq.pop()
            maxq.append(r)

            while minq and nums[minq[-1]] >= nums[r]:
                minq.pop()
            minq.append(r)

            while l <= r and (r - l + 1) * (nums[maxq[0]] - nums[minq[0]]) > k:
                if maxq and maxq[0] == l:
                    maxq.popleft()
                if minq and minq[0] == l:
                    minq.popleft()
                l += 1

            result += r - l + 1
            r += 1

        return result