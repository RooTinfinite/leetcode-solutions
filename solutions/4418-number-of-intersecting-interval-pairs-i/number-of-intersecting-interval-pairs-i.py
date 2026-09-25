class Solution:
    def countIntersectingIntervals(self, intervals: List[List[int]]) -> int:
        n = len(intervals)
        count = 0
        
        for i in range(n):
            start1 = intervals[i][0]
            end1 = intervals[i][1]
            
            for j in range(i + 1, n):
                start2 = intervals[j][0]
                end2 = intervals[j][1]
                
                if start1 <= end2 and start2 <= end1:
                    count += 1
                    
        return count