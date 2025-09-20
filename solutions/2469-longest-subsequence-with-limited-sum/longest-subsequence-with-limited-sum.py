class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        sums = []
        r = 0
        for num in nums:
            r += num
            sums.append(r)

        out = [0] * len(queries)
        i = 0
        qs = sorted(enumerate(queries), key=lambda p:p[1])
        for qi, q in qs:
            while i < len(sums) and sums[i] <= q:
                i += 1
            if q < sums[0]:
                out[qi] = 0
            else:
                out[qi] = i

        return out