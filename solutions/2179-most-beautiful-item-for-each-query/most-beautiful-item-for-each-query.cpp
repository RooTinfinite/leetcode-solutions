class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        
        int n = items.size();
        vector<int> maxBeauties(n);
        maxBeauties[0] = items[0][1];
        
        for(int i = 1; i < n; i++) {
            maxBeauties[i] = max(maxBeauties[i-1], items[i][1]);
        }
        
        vector<int> result;
        for(int query : queries) {
            int idx = binarySearch(items, query);
            result.push_back(idx < 0 ? 0 : maxBeauties[idx]);
        }
        
        return result;
    }
    
private:
    int binarySearch(vector<vector<int>>& items, int target) {
        int left = 0, right = items.size() - 1;
        int result = -1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(items[mid][0] <= target) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};