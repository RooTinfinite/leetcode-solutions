uint8_t status[40000];
int dir[5]={0, 1, 0, -1, 0};

class Solution {
public:
    int m, n;
    inline bool isOutside(int i, int j) {
        return i < 0 || i >= m || j < 0 || j >= n;
    }
    inline int idx(int i, int j) { return i * n + j; }

    void bfs(queue<int>& q, vector<vector<int>>& heights, uint8_t mark) {
        while (!q.empty()) {
            int ij=q.front();
            q.pop();
            auto [i, j]=div(ij, n);
            for (int a=0; a<4; a++) {
                int r=i+dir[a], s=j+dir[a + 1];
                if (isOutside(r, s)) continue;
                int rs = idx(r, s);
                if ((status[rs]&mark)||heights[r][s]<heights[i][j])
                    continue;
                status[rs]|=mark;
                q.push(rs);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        memset(status, 0, m*n);

        queue<int> pac, atl;
        // Pacific: top row + left col
        for (int j=0; j<n; j++) {
            status[idx(0, j)]|=1;
            pac.push(idx(0, j));
        }
        for (int i=1; i < m; i++) {
            status[idx(i, 0)] |= 1;
            pac.push(idx(i, 0));
        }
        // Atlantic: bottom row + right col
        for (int j=0; j < n; j++) {
            status[idx(m-1, j)] |= 2;
            atl.push(idx(m-1, j));
        }
        for (int i=0; i<m-1; i++) {
            status[idx(i, n-1)] |= 2;
            atl.push(idx(i, n-1));
        }

        bfs(pac, heights, 1);
        bfs(atl, heights, 2);

        vector<vector<int>> ans;
        for (int ij=0; ij<m*n; ij++) {
            if (status[ij]==3) {
                auto [i, j]=div(ij, n);
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};