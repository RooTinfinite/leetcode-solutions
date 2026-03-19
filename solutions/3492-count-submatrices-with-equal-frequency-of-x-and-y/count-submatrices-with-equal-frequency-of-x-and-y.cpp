uint64_t XY[2][1001];
class Solution {
public:
    static int numberOfSubmatrices(vector<vector<char>>& grid) {
        const int r=grid.size(), c=grid[0].size();
        memset(XY[0], 0, (c+1)*sizeof(uint64_t));
        memset(XY[1], 0, (c+1)*sizeof(uint64_t));
        int cnt=0;
        for(int i=0; i<r; i++){
            bool iEven=(i&1)==0, prv=!iEven;
            for(int j=0; j<c; j++){
                const char c=grid[i][j];
                bool isX=c=='X', isY=c=='Y';
                // pack (isX, isY) to ((uint64_t)isX<<32)+isY
                uint64_t dp=XY[iEven][j+1]=((uint64_t)isX<<32)+isY+XY[iEven][j]+XY[prv][j+1]-XY[prv][j];
                unsigned cntX=dp>>32, cntY=dp& UINT_MAX;
                cnt+=( cntX>0 & cntX==cntY);
            }
        }
        return cnt;
    }
};