import java.nio.charset.StandardCharsets;

class Solution {
    public int maxEqualRowsAfterFlips(int[][] mat) {
        int res = 0;
        int n = mat[0].length;
        Map<String, Integer> freq = new HashMap<>();

        byte[] pattern = new byte[(n + 7) / 8];  

        for (int[] row : mat) {
            int firstBit = row[0];

            Arrays.fill(pattern, (byte)0);

            for (int i = 0; i < n; i++) {
                if (row[i] != firstBit) {
                    pattern[i / 8] |= (1 << (i % 8));
                }
            }
            String key = new String(pattern, StandardCharsets.ISO_8859_1);
            res = Math.max(res, freq.merge(key, 1, Integer::sum));
        }
        return res;
    }
}