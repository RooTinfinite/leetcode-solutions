class Solution {
public:
    std::string maximumXor(std::string s, std::string t) {
        int zeros = 0;
        for (char chr : t) zeros += (chr == '0');
        int ones = (int)t.size() - zeros;

        std::string result;
        result.reserve(s.size());

        for (char chr : s) {
            // Try to match 1 from s with 0 from t first
            if ((chr == '1' && zeros) || (chr == '0' && ones)) {
                result.push_back('1');
                zeros -= (chr == '1');
                ones  -= (chr == '0');
            } else {
                result.push_back('0');
                ones  -= (chr == '1');
                zeros -= (chr == '0');
            }
        }
        return result;
    }
};