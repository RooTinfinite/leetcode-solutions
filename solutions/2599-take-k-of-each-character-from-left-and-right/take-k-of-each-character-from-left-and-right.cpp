class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        if (k == 0) return 0;
        int countA = 0, countB = 0, countC = 0;
        for (char &ch : s) {
            if (ch == 'a') countA++;
            else if (ch == 'b') countB++;
            else countC++;
        }
        int a = countA - k;
        int b = countB - k;
        int c = countC - k;
        if (a < 0 || b < 0 || c < 0) return -1;
        int left = 0, right = 0;
        int maxLen = 0;
        int c_a = 0, c_b = 0, c_c = 0;
        while (right < n) {
            if (s[right] == 'a') c_a++;
            else if (s[right] == 'b') c_b++;
            else c_c++;
            while (left <= right && (c_a > a || c_b > b || c_c > c)) {
                if (s[left] == 'a') c_a--;
                else if (s[left] == 'b') c_b--;
                else c_c--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return n - maxLen;
    }
};
