class Solution {
public:
    void calculateprefixsum(vector<vector<int>>& x){
        int m=x.size();
        int n=x[0].size();

        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                x[i][j]+=x[i][j-1];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                x[j][i]+=x[j-1][i];
            }
        }
    }
    int findsum(vector<vector<int>>& prefixSum, int r1, int r2, int c1, int c2){
        int ans=prefixSum[r2][c2];
        if(r1>0) ans-=prefixSum[r1-1][c2];
        if(c1>0) ans-=prefixSum[r2][c1-1];
        if(r1>0 && c1>0) ans+=prefixSum[r1-1][c1-1];
        return ans;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> prefixSum=mat;

        calculateprefixsum(prefixSum);
        vector<vector<int>> ans(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r1=max(0,i-k);
                int c1=max(0,j-k);
                int r2=min(i+k,m-1);
                int c2=min(j+k,n-1);
                ans[i][j]=findsum(prefixSum,r1,r2,c1,c2);
            }
        }

        return ans;
    }
};