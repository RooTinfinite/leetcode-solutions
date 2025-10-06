class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        const int n=grid.size(), m =grid[0].size();
        long long ans=0;
        vector<int> choose1;

        for (int i=0; i<n; i++) {  
            auto it = grid[i].begin()+limits[i];        
            nth_element(grid[i].begin(), it, grid[i].end(), greater<int>());
            choose1.insert(choose1.end(), grid[i].begin(), it);
        }

        if (k>choose1.size()) k=choose1.size(); // Prevent out-of-bounds
        nth_element(choose1.begin(), choose1.begin()+k, choose1.end(), greater<int>());
        return accumulate(choose1.begin(), choose1.begin()+k, 0ll);
    }
};