class Solution(object):
    def countStaircase(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        order = sorted(range(n), key=nums.__getitem__)   # positions grouped by value, ascending
        r = [0] * n      # index of position p inside `order`
        e = [0] * n      # end (exclusive) of p's value-group inside `order`
        prev = [-1] * n  # previous occurrence of the same value
        idx = 0
        while idx < n:
            v = nums[order[idx]]
            g = idx
            while g < n and nums[order[g]] == v:
                g += 1
            for t in range(idx, g):
                p = order[t]
                r[p] = t
                e[p] = g
                if t > idx:
                    prev[p] = order[t - 1]
            idx = g

        ans = n  # every single element is a staircase
        for i in range(n):
            ri = r[i]
            H = order[ri + 1] - 1 if ri + 1 < e[i] else n - 1  # last valid end so far
            L = i                                              # first valid end so far
            k = 1
            j = i + 1
            while j <= H:
                if prev[j] < i:                 # new distinct value, rank k
                    k += 1
                    t = r[j] + k - 1
                    if t >= e[j]:
                        break                   # not enough occurrences to reach count k
                    lo = order[t]               # position of its k-th occurrence
                    if lo > L:
                        L = lo
                    t += 1
                    hi = order[t] - 1 if t < e[j] else n - 1
                    if hi < H:
                        H = hi
                    if L > H:
                        break
                if j >= L:
                    ans += 1
                j += 1
        return ans