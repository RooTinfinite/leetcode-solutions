public class Solution {
    public string MaxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        int r = sum % 9;
        var ans = new System.Text.StringBuilder();
        ans.Append('9', sum / 9);
        if (r > 0) {
            ans.Append((char)('0' + r));
        }
        ans.Append('0', num - ans.Length);
        return ans.ToString();
    }
}