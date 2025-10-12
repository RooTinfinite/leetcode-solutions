class Solution {
public:
    int countOddLetters(int n) {
        int d[10] = {16577, 97, 4672, 648, 1218, 2067, 8464, 2336, 541, 17};
        int toggle = 0;

        while (n > 0) {
            int digit = n % 10;
            toggle ^= d[digit];
            n /= 10; }

        return __builtin_popcount(toggle); }
};