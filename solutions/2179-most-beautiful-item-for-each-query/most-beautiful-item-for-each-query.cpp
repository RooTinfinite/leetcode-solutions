class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Step 1: Sort items by price in ascending order
        sort(items.begin(), items.end());
        
        // Step 2: Extract prices and beauties into separate vectors
        vector<int> prices, beauties;
        for (const auto& item : items) {
            prices.push_back(item[0]);
            beauties.push_back(item[1]);
        }
        
        // Step 3: Create running maximum beauty array
        vector<int> max_beauties(1, 0);
        int curr_max = 0;
        for (int beauty : beauties) {
            curr_max = max(curr_max, beauty);
            max_beauties.push_back(curr_max);
        }
        
        // Step 4: Process each query using binary search
        vector<int> result;
        for (int query_price : queries) {
            auto index = upper_bound(prices.begin(), prices.end(), query_price) - prices.begin();
            result.push_back(max_beauties[index]);
        }
        
        return result;
    }
};
