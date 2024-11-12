class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n = items.size();
        vector<int> maxBeauty(n),prices(n);
        maxBeauty[0] = items[0][1];
        prices[0] = items[0][0];
        for(int i =1;i<n;i++) {
            prices[i] = items[i][0];
            maxBeauty[i] = max(maxBeauty[i-1],items[i][1]);
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0;i<m;i++) {
            int idx = bs(prices,queries[i]);
            if(idx == -1) {
                ans[i] = 0;
            }
            else {
                ans[i] = maxBeauty[idx];
            }
        }
        return ans;
    }

    int bs(vector<int>& prices,int target) {
        int low = 0;
        int high = prices.size() - 1;
        int result = -1;
        while(low <= high) {
            int mid = low + (high -low) / 2;
            if(prices[mid] <= target) {
                result = mid;
                low = mid +1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }
};