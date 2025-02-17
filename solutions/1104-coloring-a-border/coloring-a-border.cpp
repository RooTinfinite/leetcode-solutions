class Solution 
{
public:
    vector<vector<int>> diff = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; // left up right down
    
    bool on_border_or_neighbours_not_equal(vector<vector<bool>>& visited, int r, int c){
        if(r == 0 || r == visited.size()-1 || c == 0 || c == visited[0].size()-1) // on border conditions
            return true;
        int left = visited[r][c-1], up = visited[r-1][c], right = visited[r][c+1], down = visited[r+1][c];
        return left != 1 || up != 1 || right != 1 || down != 1; // at least one neighbour is different conditions
    }
    
    void create_border(vector<vector<int>>& grid, vector<vector<bool>> &visited, int newcolor)
    {
        for(int r=0; r<visited.size(); r++)
        {
            for(int c=0; c<visited[0].size(); c++)
                if(visited[r][c] == 1 && on_border_or_neighbours_not_equal(visited, r, c))
                    grid[r][c] = newcolor;
        }
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int oldcolor, vector<vector<bool>> &visited)
    {
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || visited[r][c] == 1 || grid[r][c] != oldcolor)
            return;
        visited[r][c] = 1;
        for(const auto &d : diff)
            dfs(grid, r+d[0], c+d[1], oldcolor, visited);
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        dfs(grid, row, col, grid[row][col], visited);
        create_border(grid, visited, color);
        return grid;
    }
};