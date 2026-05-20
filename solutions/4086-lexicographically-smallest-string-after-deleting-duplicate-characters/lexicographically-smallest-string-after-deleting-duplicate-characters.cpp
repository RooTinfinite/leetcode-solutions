class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        int r[26] = {0}, in[26] = {0};
        for (char c : s) r[c - 'a']++;
        string ans;
        for (char c : s) {
            int i = c - 'a';
            r[i]--;
            while (!ans.empty()) {
                int j = ans.back() - 'a';
                if (ans.back() > c && (r[j] > 0 || in[j] > 1)) {
                    in[j]--;
                    ans.pop_back();
                } else break;
            }
            ans += c;
            in[i]++;
        }
        while (!ans.empty() && in[ans.back() - 'a'] > 1) {
            in[ans.back() - 'a']--;
            ans.pop_back();
        }
        return ans;
    }
};