class Solution {
public:
    string minWindow(string s, string t) {
        struct element {
            int index;
            char char_val;
        };
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }
        unordered_map<char, int> dictT;
        for (int i = 0; i < t.length(); i++) {
            dictT[t[i]]++;
        }
        int required = dictT.size();
        vector<element> filteredS;
        for (int i = 0; i < s.length(); i++) {
            if (dictT.find(s[i]) != dictT.end()) filteredS.push_back({i, s[i]});
        }
        int l = 0, r = 0, formed = 0;
        unordered_map<char, int> windowCounts;
        vector<int> ans = {-1, 0, 0};
        while (r < filteredS.size()) {
            char c = filteredS[r].char_val;
            windowCounts[c]++;
            if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c]) {
                formed++;
            }
            while (l <= r && formed == required) {
                char c = filteredS[l].char_val;
                int end = filteredS[r].index;
                int start = filteredS[l].index;
                if (ans[0] == -1 || end - start + 1 < ans[0]) {
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }
                windowCounts[c]--;
                if (dictT.find(c) != dictT.end() &&
                    windowCounts[c] < dictT[c]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};