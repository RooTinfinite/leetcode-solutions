class Solution {
public:
    char kthCharacter(string s, long long k) {
        stringstream ss(s);
        string t;

        while (ss >> t) {
            int n = t.length();
            // Directly calculate the length of expanded string, and subtract it from k.
            long long len = 1LL * (n + 1) * n / 2 + 1;
            if (k < len) {
                break;
            }
            k -= len;
        }

        // find which character it ends.
        int i = 1;
        while (k >= i) {
            k -= i++;
        }

        // In case it achieves the end of t, character should be ' '; otherwise, character should be t[i - 1].
        return (i == t.length() + 1) ? ' ' : t[i - 1];
    }
};