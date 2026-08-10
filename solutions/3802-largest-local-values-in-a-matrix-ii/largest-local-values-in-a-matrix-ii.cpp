class Solution {
public:
    int m,n;
    vector<vector<vector<int>>>pfx;
    bool check(int i,int j,vector<vector<int>>& mat){
        int val=mat[i][j];
        int r1=max(0,i-val);
        int r2=min(m-1,i+val);
        int c1=max(0,j-val);
        int c2=min(n-1,j+val);
        int cnt=pfx[val][r2+1][c2+1]-pfx[val][r1][c2+1]+pfx[val][r1][c1]-pfx[val][r2+1][c1];
        int dr[4]={-val,-val,val,val};
        int dc[4]={-val,val,-val,val};
        
        for(int k=0;k<4;k++){
                int ni=i+dr[k];
                int nj=j+dc[k];
                if(ni>=0 && ni<m && nj>=0 && nj<n && mat[ni][nj]>val)cnt--;
        }    
        return cnt==0;
    }
    int countLocalMaximums(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        int ans=0;
        pfx.resize(201,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int v=0;v<=200;v++){
            for(int i=0;i<m;i++){
                int rs=0;
                for(int j=0;j<n;j++){
                    if(matrix[i][j]>v)rs+=1;
                    pfx[v][i+1][j+1]=rs+pfx[v][i][j+1];
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0)continue;
                if(check(i,j,matrix))ans++;
            }
        }
        return ans;
    }
};