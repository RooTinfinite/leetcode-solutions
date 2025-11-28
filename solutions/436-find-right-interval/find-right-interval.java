import java.util.TreeMap;
import java.util.Map;

class Solution {
    public int[] findRightInterval(int[][] intervals) {
        int n = intervals.length;
        
        // Step 1: Store (Start Time, Original Index) in a TreeMap.
        // TreeMap keeps keys sorted and allows O(logN) ceiling lookup.
        TreeMap<Integer, Integer> startMap = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            startMap.put(intervals[i][0], i);
        }
        
        int[] result = new int[n];
        
        // Step 2: Iterate through the original intervals and search
        for (int i = 0; i < n; i++) {
            int end_i = intervals[i][1];
            
            // Find the smallest key (start time) >= end_i
            // ceilingKey is O(logN)
            Integer rightStart = startMap.ceilingKey(end_i);
            
            if (rightStart == null) {
                // No right interval found
                result[i] = -1;
            } else {
                // Retrieve the original index of the right interval
                result[i] = startMap.get(rightStart);
            }
        }
        
        return result;
    }
}