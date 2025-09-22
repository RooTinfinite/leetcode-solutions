class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        int n = r1.size();
        int ans = 0;

        vector<pair<int,int>> diff;
        for (int i = 0; i < n; i++) {
            diff.push_back({r1[i] - r2[i], i});
            ans += r2[i]; // start with all from reward2
        }

        sort(diff.rbegin(), diff.rend());

        for (int i = 0; i < k; i++) {
            ans += diff[i].first; // add the extra gain for top k
        }

        return ans;
    }
};