class Solution:
    def canMakeSubsequence(self, s: str, t: str) -> bool:
        if len(s) > len(t):
            return False

        n, m = len(s), len(t)

        if n == 0:
            return True

        left = [-1] * n
        right = [-1] * n

        p = 0
        for i in range(n):
            while p < m and t[p] != s[i]:
                p += 1
            if p == m:
                break
            left[i] = p
            p += 1

        if left[-1] != -1:
            return True

        p = m - 1
        for i in range(n - 1, -1, -1):
            while p >= 0 and t[p] != s[i]:
                p -= 1
            if p < 0:
                break
            right[i] = p
            p -= 1

        for i in range(n):
            if (i == 0 or left[i - 1] != -1) and \
               (i == n - 1 or right[i + 1] != -1):

                L = -1 if i == 0 else left[i - 1]
                R = m if i == n - 1 else right[i + 1]

                if L + 1 < R:
                    return True

        return False