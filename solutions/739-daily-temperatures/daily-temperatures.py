class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans = [0] * len(temperatures)
        stack = []

        for i in range(len(temperatures) - 1, -1, -1):
            if not stack:
                stack.append(i)
                ans[i] = 0
            else:
                while stack and temperatures[i] >= temperatures[stack[-1]]:
                    stack.pop()

                if not stack:
                    ans[i] = 0
                else:
                    ans[i] = stack[-1] - i

                stack.append(i)

        return ans