class Solution:
    def longestSubarray(self, nums: list[int], k: int) -> int:
        n = len(nums)
        prefix = [s % k for s in accumulate(nums, initial=0)]

        first, last = [n + 1] * k, [-1] * k
        for i, c in enumerate(prefix):
            last[c] = i
        for i in reversed(range(n + 1)):
            first[prefix[i]] = i

        best = max(0, max(map(int.__sub__, last, first)))  # no negation

        doubled = [2 * x % k for x in nums]
        nxt = [n + 1] * k
        i = n - 1
        for c in sorted(range(k), key=first.__getitem__, reverse=True):
            start = first[c]
            if start > n:
                continue
            while i >= start:
                nxt[doubled[i]] = i
                i -= 1
            ends = last[c:] + last[:c]  # ends[v] = last[(c + v) % k]
            end = max(compress(ends, map(lt, nxt, ends)), default=-1)
            best = max(best, end - start)
        return best