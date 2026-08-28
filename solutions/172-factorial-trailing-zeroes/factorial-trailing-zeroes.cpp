class Solution {
public:
    int trailingZeroes(int n) {
        int zeroCount = 0;
        long long currentMultiple = 5;
        while (n >= currentMultiple) {
            zeroCount += (n / currentMultiple);
            currentMultiple *= 5;
        }
        return zeroCount;
    }
};