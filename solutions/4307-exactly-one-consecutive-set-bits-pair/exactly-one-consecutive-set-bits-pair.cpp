class Solution {
public:
    bool consecutiveSetBits(int n) {
        return __builtin_popcount(n & (n >> 1)) == 1;
    }
};