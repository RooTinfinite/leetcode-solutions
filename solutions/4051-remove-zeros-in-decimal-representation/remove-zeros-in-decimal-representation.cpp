class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        return stoll(s);
    }
};