public class Solution {
    public int MySqrt(int x) {
        if (x < 2)
            return x;
        double x0 = x;
        double x1 = (x0 + x / x0) / 2.0;
        while (Math.Abs(x0 - x1) >= 1) {
            x0 = x1;
            x1 = (x0 + x / x0) / 2.0;
        }

        return (int)x1;
    }
}