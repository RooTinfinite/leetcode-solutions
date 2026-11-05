class Solution:
    def maxSum(self, nums: list[int], length: int, k: int) -> int:
        n = len(nums)
        window_sum = sum(nums[:length])

        if k == 0 or length == n:
            answer = window_sum
            for right in range(length, n):
                window_sum += nums[right] - nums[right - length]
                answer = max(answer, window_sum)
            return answer

        order = sorted(range(n), key=nums.__getitem__)
        upper_bound = sum(nums[i] for i in order[n - length:])

        k = min(k, length, n - length)
        if k == min(length, n - length):
            return upper_bound

        answer = window_sum
        for left in range(n - length + 1):
            right = left + length
            candidate = window_sum
            low, high = 0, n - 1

            for _ in range(k):
                while not left <= order[low] < right:
                    low += 1
                while left <= order[high] < right:
                    high -= 1

                gain = nums[order[high]] - nums[order[low]]
                if gain <= 0:
                    break

                candidate += gain
                low += 1
                high -= 1

            answer = max(answer, candidate)
            if answer == upper_bound:
                return answer

            if right < n:
                window_sum += nums[right] - nums[left]

        return answer