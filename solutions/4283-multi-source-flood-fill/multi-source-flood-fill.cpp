class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        //mark the already colored one
        int total_colored=0;
        for(auto &s : sources){
            int r = s[0], c = s[1], color = s[2];
            grid[r][c] = color;
            total_colored++;
            q.push({r,c});
        }

        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};

        while(!q.empty() && total_colored < m*n){
            int size = q.size();
            map<pair<int,int>, int> updates;

            while(size--){
                auto [r,c] = q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                        updates[{nr,nc}] = max(updates[{nr,nc}], grid[r][c]);
                    }
                }
            }

            for(auto &it : updates){
                int r = it.first.first;
                int c = it.first.second;
                grid[r][c] = it.second;
                total_colored++;
                q.push({r,c});
            }
        }

        return grid;
    }
};