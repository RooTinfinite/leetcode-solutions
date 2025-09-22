class Solution:
    def maximizeWin(self, prizePositions: List[int], k: int) -> int:
        # count of prizes for all intervals
        # (count, end position of interval)        
        intervals = []
        # max stack of intervals
        # (count, end position of interval),
        # There can't be interval with bigger count before the interval
        max_beffore = []
        start_inx = 0 # start index of the current interval
        count = 0 # count of the current interval
        for inx, pos in enumerate(prizePositions):
            count += 1
            # subtract prizes from the current interval if they are not covered by the interval
            while pos-k > prizePositions[start_inx]:
                count -= 1
                start_inx += 1
            intervals.append((count, pos))
            if not max_beffore or max_beffore[-1][0] < count:
                max_beffore.append((count, pos))

        max_solution = 0
        while intervals:
            # the last interval for the current solution
            count, pos = intervals.pop()
            # max_beffore stores only intervals before the last interval,
            # max_beffore is a max stack,
            # so the top of the max possible has the max count among all values in the max_beffore
            while max_beffore and max_beffore[-1][1] >= pos-k:
                max_beffore.pop()
            # The soluthon if the current last interval is the last
            candidate = count+(0 if not max_beffore else max_beffore[-1][0])
            # we need to find maximum among all candidates
            max_solution = max(candidate, max_solution)
        return max_solution
            