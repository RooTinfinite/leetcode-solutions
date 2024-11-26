class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            int j = 0;
            for (int k = 0; k < queries[i].size(); k++) {
                if (j < pattern.size() && queries[i][k] == pattern[j]) {
                    j++;
                } else if (queries[i][k] >= 'A' && queries[i][k] <= 'Z') {
                    ans.push_back(false);
                    break;
                }
                if (k == queries[i].size() - 1) {
                    if (j == pattern.size()) {
                        ans.push_back(true);
                    } else {
                        ans.push_back(false);
                    }
                }
            }
        }
        return ans;
    }
};