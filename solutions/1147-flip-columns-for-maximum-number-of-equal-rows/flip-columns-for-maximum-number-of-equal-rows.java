class Solution {
    public int maxEqualRowsAfterFlips(int[][] mat) {
        int res = 0;
        int n = mat[0].length;
        Map<BitSet, Integer> freq = new HashMap<>();
        
        for (int[] row : mat) {
            BitSet same = new BitSet(n);
            same.set(0);
            for (int i = 1; i < n; i++) {
                if (row[0] != row[i]) {
                    same.set(i);
                }
            }
            
            int count = freq.merge(same, 1, Integer::sum);
            res = Math.max(res, count);
        }
        return res;
    }
}