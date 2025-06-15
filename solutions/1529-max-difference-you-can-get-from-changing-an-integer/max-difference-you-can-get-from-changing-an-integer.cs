public class Solution {
    public int MaxDiff(int num) {
        Func<int, int, string> change = (x, y) => {
            var numStr = num.ToString();
            return new string(numStr
                                  .Select(digit => (digit - '0') == x
                                                       ? (char)('0' + y)
                                                       : digit)
                                  .ToArray());
        };

        int minNum = num;
        int maxNum = num;
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                string res = change(x, y);
                // Check if there are leading zeros
                if (res[0] != '0') {
                    int res_i = int.Parse(res);
                    minNum = Math.Min(minNum, res_i);
                    maxNum = Math.Max(maxNum, res_i);
                }
            }
        }
        return maxNum - minNum;
    }
}