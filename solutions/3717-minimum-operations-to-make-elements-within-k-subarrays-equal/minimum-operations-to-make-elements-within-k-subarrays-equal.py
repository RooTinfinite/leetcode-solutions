class Solution:
    def minOperations(self, nums: List[int], x: int, k: int) -> int:
        n = len(nums)
        left, right = SortedList(), SortedList()
        sum_l = sum_r = 0
        ops = [0] * n

        for i, value in enumerate(nums):
            if not left or value <= left[-1]:
                left.add(value)
                sum_l += value
            else:
                right.add(value)
                sum_r += value
            if i >= x:
                value = nums[i - x]
                if value in left:
                    left.remove(value)
                    sum_l -= value
                else:
                    right.remove(value)
                    sum_r -= value
            if len(left) > len(right) + 1:
                value = left.pop()
                right.add(value)
                sum_l -= value
                sum_r += value
            elif len(left) < len(right):
                value = right.pop(0)
                left.add(value)
                sum_l += value
                sum_r -= value
            if i >= x - 1:
                mid = left[-1]
                ops[i] = mid * len(left) - sum_l + sum_r - mid * len(right)

        pre = [0] * (n + 1)
        cur = [inf] * (n + 1)
        for j in range(1, k + 1):
            for i in range(n + 1):
                cur[i] = inf
            for i in range(j * x, n + 1):
                cur[i] = min(cur[i - 1], pre[i - x] + ops[i - 1])
            pre, cur = cur, pre
        return pre[n]