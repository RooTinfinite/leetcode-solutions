public class Solution {
    public IList<string> GenerateParenthesis(int n) {
        if (n == 0) {
            return new List<string> { "" };
        }

        List<string> answer = new List<string>();
        for (int leftCount = 0; leftCount < n; ++leftCount) {
            IList<string> leftStrings = GenerateParenthesis(leftCount);
            IList<string> rightStrings = GenerateParenthesis(n - 1 - leftCount);
            foreach (string leftString in leftStrings) {
                foreach (string rightString in rightStrings) {
                    answer.Add("(" + leftString + ")" + rightString);
                }
            }
        }

        return answer;
    }
}