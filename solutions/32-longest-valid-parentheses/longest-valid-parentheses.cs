public class Solution {
    public int LongestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.Length; i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                maxlength = Math.Max(maxlength, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }

        left = right = 0;
        for (int i = s.Length - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                maxlength = Math.Max(maxlength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }

        return maxlength;
    }
}