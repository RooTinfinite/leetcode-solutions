class Solution:
    def minMoves(self, balance):
        s = 0
        idx = -1
        n = len(balance)

        for i in range(n):
            s += balance[i]
            if balance[i] < 0:
                idx = i

        if s < 0:
            return -1
        if idx == -1:
            return 0

        val = balance[idx]
        left = (idx - 1 + n) % n
        right = (idx + 1) % n
        dist = 1
        ans = 0

        while val < 0:
            if balance[left] > 0:
                take = min(balance[left], -val)
                val += take
                ans += take * dist

            if val < 0 and balance[right] > 0:
                take = min(balance[right], -val)
                val += take
                ans += take * dist

            left = (left - 1 + n) % n
            right = (right + 1) % n
            dist += 1

        return ans