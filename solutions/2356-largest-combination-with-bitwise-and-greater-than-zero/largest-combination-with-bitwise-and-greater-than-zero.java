class Solution {
    private static final int BitMax = 24;
    
    public int largestCombination(int[] candidates) {
        int maxSet = 1;
        int mask = 1;
        
        for (int shift = 0; shift < BitMax; shift++) {
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