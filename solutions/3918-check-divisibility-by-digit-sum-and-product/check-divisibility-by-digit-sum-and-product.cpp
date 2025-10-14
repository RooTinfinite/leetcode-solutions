class Solution {
public:
    bool checkDivisibility(int n) {
        return n % ([&](string s) {
            return accumulate(s.begin(), s.end(), 0, [](int a, char c) { return a + (c - '0'); })
                 + accumulate(s.begin(), s.end(), 1, [](int a, char c) { return a * (c - '0'); });
        })(to_string(n)) == 0;
    }
};
