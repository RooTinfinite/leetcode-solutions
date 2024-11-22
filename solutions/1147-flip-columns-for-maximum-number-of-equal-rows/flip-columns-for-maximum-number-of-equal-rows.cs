public class Solution {
    public int MaxEqualRowsAfterFlips(int[][] mat) {
        Dictionary<string, int> patFreq = new Dictionary<string, int>();
        
        foreach (int[] row in mat) {
            StringBuilder pattern = new StringBuilder();
            if (row[0] == 0) {
                foreach (int bit in row) pattern.Append(bit);
            } else {
                foreach (int bit in row) pattern.Append(bit ^ 1);
            }
            
            string key = pattern.ToString();
            if (!patFreq.ContainsKey(key)) patFreq[key] = 0;
            patFreq[key]++;
        }
        
        return patFreq.Values.Max();
    }
}