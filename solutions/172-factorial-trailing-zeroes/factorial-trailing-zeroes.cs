public class Solution {
    public int TrailingZeroes(int n) {
        int zeroCount = 0;
        long currentMultiple = 5;
        while (n >= currentMultiple) {
            zeroCount += (int)(n / currentMultiple);
            currentMultiple *= 5;
        }

        return zeroCount;
    }
}