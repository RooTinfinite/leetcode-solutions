class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        # [value, left, right]
        stack = []

        for i in range(n):
            curr_val = nums[i]
            curr_left = i
            curr_right = i

            while stack and stack[-1][0] > nums[i]:
                top_val, top_left, top_right = stack.pop()
                curr_val = max(curr_val, top_val)
                curr_left = top_left

            stack.append((curr_val, curr_left, curr_right))

        for i in range(len(stack)):
            for j in range(stack[i][1], stack[i][2] + 1):
                ans[j] = stack[i][0]

        return ans