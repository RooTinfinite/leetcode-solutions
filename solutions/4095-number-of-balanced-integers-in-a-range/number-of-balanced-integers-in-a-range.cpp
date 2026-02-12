class Solution {
public:
    static constexpr int MAX_DIGITS = 16;
    static constexpr int MAX_DIFF   = MAX_DIGITS * 10;
    static constexpr int DIFF_SHIFT = MAX_DIFF / 2;
    long long cache[MAX_DIGITS + 1][MAX_DIFF][2];

    vector<int> digits;

    void reset_cache() {
        fill(&cache[0][0][0], &cache[0][0][0] + (MAX_DIGITS + 1) * MAX_DIFF * 2, -1LL);
    }

    long long dp(int i = 0, int diff = 0, bool digitlim = true) {
        if (i == digits.size())
            return diff == 0;

        // Use cached value if possible
        // We shift diff to half since we can have both positive and negative values
        if (cache[i][diff + DIFF_SHIFT][digitlim] != -1)
            return cache[i][diff + DIFF_SHIFT][digitlim];

        int maxdigit = digitlim ? digits[i] : 9;
        int possign = 2 * (i % 2) - 1;

        long long result = 0;
        for (int digit = 0; digit <= maxdigit; ++digit) {
            int diff_next = diff + digit * possign;
            bool digitlim_next = (digit == maxdigit) && (digitlim);
            result += dp(i + 1, diff_next, digitlim_next);
        }

        return cache[i][diff + DIFF_SHIFT][digitlim] = result;
    }

    long long solve(long long num) {
        string snum = to_string(num);
        digits.push_back(0);
        for (int i = 0; i < snum.size(); ++i) 
            digits.push_back(snum[i] - '0');

        reset_cache();
        long long result = dp();
        digits.clear();

        return result;
    }

    long long countBalanced(long long low, long long high) {
        return solve(high) - solve(low - 1);
    }
};