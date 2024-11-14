public class Solution {
    public IList<int> GetRow(int rowIndex) {
        List<int> res = new List<int> {1};
        long prev = 1;
        for (int k = 1; k <= rowIndex; k++) {
            long next_val = prev * (rowIndex - k + 1) / k;
            res.Add((int)next_val);
            prev = next_val;
        }
        return res;
    }
}