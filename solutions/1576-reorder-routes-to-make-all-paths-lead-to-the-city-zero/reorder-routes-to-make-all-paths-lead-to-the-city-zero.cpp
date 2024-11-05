class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> grid(n);
        vector<int> vis(n, 0);

        for (const auto& conn : connections) {
            int src = conn[0];
            int dest = conn[1];
            grid[src].push_back(-1 * dest);
            grid[dest].push_back(src);
        }

        return solve(grid, 0, vis);
    }

private:
    int solve(vector<vector<int>>& grid, int val, vector<int>& vis) {
        if (vis[val] == 1) {
            return 0;
        }
        int ans = 0;
        vis[val] = 1;
        for (int ele : grid[val]) {
            if (vis[abs(ele)] == 1) {
                continue;
            }
            if (ele < 0) {
                ans += 1;
            }
            ans += solve(grid, abs(ele), vis);
        }
        return ans;
    }
};