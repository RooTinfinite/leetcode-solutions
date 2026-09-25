class Solution {
    public int countIntersectingIntervals(int[][] intervals) {
        int n = intervals.length;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int start1 = intervals[i][0];
            int end1 = intervals[i][1];
            
            for (int j = i + 1; j < n; j++) {
                int start2 = intervals[j][0];
                int end2 = intervals[j][1];
                
                if (start1 <= end2 && start2 <= end1) {
                    count++;
                }
            }
        }
        
        return count;
    }
}