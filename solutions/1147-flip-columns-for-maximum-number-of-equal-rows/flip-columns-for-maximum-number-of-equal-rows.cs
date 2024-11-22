public class Solution {
    public int MaxEqualRowsAfterFlips(int[][] matrix) {
        var count = new Dictionary<string, int>();
        
        foreach (var row in matrix) {
            var key = new int[row.Length];
            for (int i = 0; i < row.Length; i++) {
                key[i] = row[0] == 1 ? 1 - row[i] : row[i];
            }
            var rowKey = string.Join(",", key);
            count[rowKey] = count.GetValueOrDefault(rowKey, 0) + 1;
        }
        
        return count.Values.Max();
    }
}