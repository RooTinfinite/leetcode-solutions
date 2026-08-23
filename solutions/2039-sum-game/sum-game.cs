public class Solution {
    public bool SumGame(string num) {
        int n = num.Length;
        var left = Get(num.Substring(0, n / 2));
        var right = Get(num.Substring(n / 2, n / 2));

        int n0 = left.Item1, q0 = left.Item2;
        int n1 = right.Item1, q1 = right.Item2;

        return ((q0 + q1) % 2 == 1) || (n0 - n1 != (q1 - q0) * 9 / 2);
    }

    private (int, int) Get(string s) {
        int nn = 0, qq = 0;
        foreach (char ch in s) {
            if (ch == '?') {
                qq++;
            } else {
                nn += (ch - '0');
            }
        }
        return (nn, qq);
    }
}