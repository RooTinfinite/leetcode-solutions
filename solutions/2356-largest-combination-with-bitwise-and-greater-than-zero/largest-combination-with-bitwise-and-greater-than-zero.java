public class Solution {
    private static final int BIT_MAX = 24;
    
    public int largestCombination(int[] candidates) {
        int maxSet = 1;
        int mask = 1;
        
        for (int shift = 0; shift < BIT_MAX; shift++) {
            int count = 0;
            for (int num : candidates) {
                if ((num & mask) != 0) {
                    count++;
                }
            }
            maxSet = Math.max(maxSet, count);
            mask <<= 1;
        }
        return maxSet;
    }
}