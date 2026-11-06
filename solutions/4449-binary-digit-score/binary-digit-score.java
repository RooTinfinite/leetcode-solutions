class Solution {
    public int calculateScore(int a, int b) {
        int c = 0, d = 0;
        while (a > 0) {
            c += a & 1;
            a >>= 1;
        }
        while (b > 0) {
            d += b & 1;
            b >>= 1;
        }
        if (c >= d) {
            return c * d;
        }
        return d / c;
    }
}