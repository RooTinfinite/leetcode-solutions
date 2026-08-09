class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        vector<vector<int>> ans;
        int n1 = s1.size(), n2 = s2.size();
        int i = 0, j = 0;

        while (i < n1 || j < n2) {
            int t;

            if (i == n1) {
                t = s2[j][0];
            } else if (j == n2) {
                t = s1[i][0];
            } else {
                t = min(s1[i][0], s2[j][0]);
            }

            int x1 = 0;
            if (i < n1) {
                x1 = s1[i][1];
            }

            int x2 = 0;
            if (j < n2) {
                x2 = s2[j][1];
            }

            ans.push_back({t, x1 + x2});

            if (i < n1 && s1[i][0] == t) {
                i++;
            }

            if (j < n2 && s2[j][0] == t) {
                j++;
            }
        }

        return ans;
    }
};