#define F first
#define S second

const vector<vector<int>> neighbours = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

struct Node {
    int time;
    int row, col;
    
    Node (int _time, int _row, int _col) : time(_time), row(_row), col(_col) {}
    
    bool operator < (const Node& rhs) const {
        if (time != rhs.time) return time < rhs.time;
        if (row != rhs.row) return row < rhs.row;
        return col < rhs.col;
    }
};

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size(); 
        
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        vector<vector<int>> time_to_reach(rows, vector<int>(cols, 1e9));
        time_to_reach[0][0] = 0;
        
        set<Node> q;
        for (int r = 0; r < rows; r ++) {
            for (int c = 0; c < cols; c ++) {
                q.insert(Node(time_to_reach[r][c], r, c));
            }
        }
        
        while (!q.empty()) {
            Node cur = *q.begin();
            q.erase (q.begin());
            
            for (auto i : neighbours) {
                int r = cur.row + i[0], c = cur.col + i[1];
                if (r < 0 || r >= rows || c < 0 || c >= cols) continue;
                
                int wait_time = max(0, grid[r][c] - cur.time - 1);
                if (wait_time % 2 != 0) wait_time ++;
            
                int new_time  = cur.time + wait_time + 1;
                if (time_to_reach[r][c] > new_time) {
                    q.erase (Node(time_to_reach[r][c], r, c));
                    time_to_reach[r][c] = new_time;
                    q.insert (Node(time_to_reach[r][c], r, c));
                }
            }
        }
        
        return time_to_reach[rows-1][cols-1];
    }
};