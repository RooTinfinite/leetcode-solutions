public class Solution {
    public int ClosestTarget(string[] W, string T, int s) {
        int a = int.MaxValue, n = W.Length;
        for (int i = 0; i < n; i++) {
            if (W[i] == T) {
                int d = Math.Abs(i - s);
                a = Math.Min(a, Math.Min(d, n - d));
            }
        }
        return a == int.MaxValue ? -1 : a;
    }
}