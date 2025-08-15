class Solution:
    def minSessions(self, tasks: List[int], sessionTime: int) -> int:
        n = len(tasks)

        def clearBit(x, k):
            return ~(1 << k) & x

        @lru_cache(None)
        def dp(mask, remainTime):
            if mask == 0: return 0

            ans = n  # There is up to N work sessions
            for i in range(n):
                if (mask >> i) & 1:
                    newMask = clearBit(mask, i)
                    if tasks[i] <= remainTime:
                        ans = min(ans, dp(newMask, remainTime - tasks[i]))  # Consume current session
                    else:
                        ans = min(ans, dp(newMask, sessionTime - tasks[i]) + 1)  # Create new session

            return ans

        return dp((1 << n) - 1, 0)