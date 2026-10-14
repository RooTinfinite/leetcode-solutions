class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
        int nines = sum / 9;
        int digit = sum % 9;

        if (nines + (digit > 0) > num) return "";

        std::string ans(nines, '9');

        if (nines == num) return ans;

        ans += std::to_string(digit);
        ans.append(num - ans.size(), '0');

        return ans;
    }
};