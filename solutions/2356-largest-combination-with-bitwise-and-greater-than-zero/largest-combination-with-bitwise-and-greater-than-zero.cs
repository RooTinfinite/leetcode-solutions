public class Solution {
    private const int BitMax = 24;
    
    public int LargestCombination(int[] candidates) {
        int maxSet = 1;
        int mask = 1;
        
        for (int shift = 0; shift < BitMax; shift++) {
            int count = 0;
            foreach (int num in candidates) {
                if ((num & mask) != 0) {
                    count++;
                }
            }
            maxSet = Math.Max(maxSet, count);
            mask <<= 1;
        }
        return maxSet;
    }
}