class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        // Create a 2D vector to store the answer with the same size as the grid
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        
        // Traverse the grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // Create two sets to store distinct values
                set<int> a, b;
                
                // Traverse diagonally upwards to the top-left corner
                for (int k = 1; i - k >= 0 && j - k >= 0; k++) {
                    a.insert(grid[i - k][j - k]);
                }
                
                // Traverse diagonally downwards to the bottom-right corner
                for (int k = 1; i + k < grid.size() && j + k < grid[0].size(); k++) {
                    b.insert(grid[i + k][j + k]);
                }
                
                // Calculate the absolute difference between the sizes of the two sets
                ans[i][j] = abs(static_cast<int>(a.size() - b.size()));
            }
        }
        
        // Return the answer
        return ans;
    }
};

        
     