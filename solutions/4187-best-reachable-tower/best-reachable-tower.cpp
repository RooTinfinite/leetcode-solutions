class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int> ans = {INT_MAX, INT_MAX};
        int bestQuality = 0;

        for (auto& t : towers) {
            int dist = abs(center[0] - t[0]) + abs(center[1] - t[1]);
            if (dist <= radius) {
                if (t[2] > bestQuality) {
                    bestQuality = t[2];
                    ans = {t[0], t[1]};
                } else if (t[2] == bestQuality) {
                    ans = min(ans, {t[0], t[1]});
                }
            }
        }

        if (ans[0] == INT_MAX) return {-1, -1};
        return ans;
    }
};