class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        if (n == 0) {
            return std::vector<std::string>{""};
        }
        std::vector<std::string> answer;
        for (int leftCount = 0; leftCount < n; ++leftCount) {
            auto leftStrings = generateParenthesis(leftCount);
            auto rightStrings = generateParenthesis(n - 1 - leftCount);
            for (const auto& leftString : leftStrings) {
                for (const auto& rightString : rightStrings) {
                    answer.push_back("(" + leftString + ")" + rightString);
                }
            }
        }
        return answer;
    }
};