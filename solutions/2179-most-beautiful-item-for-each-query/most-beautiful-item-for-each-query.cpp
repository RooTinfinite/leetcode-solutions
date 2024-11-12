class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<pair<int, int>> queriesWithIndex;
        for (int i = 0; i < queries.size(); i++) {
            queriesWithIndex.push_back({queries[i], i});
        }
        sort(queriesWithIndex.begin(), queriesWithIndex.end());
        
        vector<int> res(queries.size());
        int maxBea = 0;
        int j = 0;
        for (auto [q, i] : queriesWithIndex) {
            while (j < items.size() && items[j][0] <= q) {
                maxBea = max(maxBea, items[j][1]);
                j++;
            }
            res[i] = maxBea;
        }
        return res;
    }
};