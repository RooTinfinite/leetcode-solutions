class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> result;

        for (int i = 0; i < grid.size(); ++i) {
            if (i % 2 != 0) {
                reverse(grid[i].begin(), grid[i].end());}}

        bool take = true;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (take) {
                    result.push_back(grid[i][j]);}
                take = !take;} }

        return result;}};