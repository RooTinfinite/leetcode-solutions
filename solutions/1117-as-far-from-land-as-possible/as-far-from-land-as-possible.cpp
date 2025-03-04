class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        if (q.size() == 0 || q.size() == n * n) return -1;
        int maxd=-1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while (!q.empty()){
            int size=q.size();
            maxd++;
            for (int i=0;i<size;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int j=0;j<4;j++){
                    int nrow=row+drow[j];
                    int ncol=col+dcol[j];
                    if (nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol] == 0){
                        grid[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return maxd;
    }
};