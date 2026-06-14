class Solution {
    public int minimumIndex(int[] capacity, int itemSize) {
        
        int res = Integer.MAX_VALUE;
        int idx = -1; 

        for (int i = 0; i < capacity.length; i++) {
            if (itemSize <= capacity[i] && capacity[i] < res) {
                res = capacity[i];
                idx = i; }
        }
        return idx; }
}