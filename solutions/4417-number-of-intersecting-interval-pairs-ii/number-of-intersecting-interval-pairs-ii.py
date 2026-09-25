import bisect

class Solution:
    def countIntersectingIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], x[1]))
        
        starts = [interval[0] for interval in intervals]
        n = len(intervals)
        total_pairs = 0
        
        for i in range(n):
            end1 = intervals[i][1]
            idx = bisect.bisect_right(starts, end1, i + 1, n)
            total_pairs += (idx - (i + 1))
            
        return total_pairs