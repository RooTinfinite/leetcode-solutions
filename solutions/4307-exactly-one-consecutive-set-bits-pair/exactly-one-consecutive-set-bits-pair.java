class Solution {
    public boolean consecutiveSetBits(int n) {
        return Integer.bitCount(n & (n >> 1)) == 1;
    }
}