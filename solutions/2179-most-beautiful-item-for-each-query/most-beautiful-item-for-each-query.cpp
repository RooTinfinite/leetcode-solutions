class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Sort items by price in ascending order
        sort(items.begin(), items.end());
        map<int, int> priceToBeauty;
        int maxBeauty = 0;
        
        // Build price to maximum beauty mapping
        for (const auto& item : items) {
            maxBeauty = max(maxBeauty, item[1]);
            priceToBeauty[item[0]] = maxBeauty;
        }
        
        // Process each query using binary search
        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            auto it = priceToBeauty.upper_bound(queries[i]);
            result[i] = it == priceToBeauty.begin() ? 0 : prev(it)->second;
        }
        return result;
    }
};