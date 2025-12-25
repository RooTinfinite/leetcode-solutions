class Solution {
public:
    long long lastInteger(long long n) {
        constexpr long long MASK = 0xAAAAAAAAAAAAAAALL; // ...1010
        return ((n - 1) & MASK) + 1;
    }
};