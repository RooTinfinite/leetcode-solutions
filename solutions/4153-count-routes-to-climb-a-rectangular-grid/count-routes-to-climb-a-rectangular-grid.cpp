#define ll long long
class Solution {
public:
    int MOD=1e9+7;
    int numberOfRoutes(vector<string>& grid, int d) {
        int n=grid.size();
        int m=grid[0].size();

        vector<ll> prev(m,0),curr(m,0);

        for(int i=0;i<m;i++) if(grid[n-1][i]=='.') prev[i]=1;

        int l=floor(sqrt(1LL*d*d-1));

        for(int i=n-1;i>=0;i--){
            vector<ll> pre(m+1,0);
            for(int j=0;j<m;j++) pre[j+1]=(pre[j]+prev[j])%MOD;

            for(int j=0;j<m;j++){
                if(grid[i][j]=='#'){
                    curr[j]=0;
                    continue;
                }
                int left=max(0,j-d);
                int right=min(m-1,j+d);
                ll rr=(pre[right+1]-pre[left]+MOD)%MOD;
                curr[j]=(rr-prev[j]+MOD)%MOD;
            }

            if(i==0) break;

            vector<ll> next(m,0);
            vector<ll> comb(m+1,0);

            for(int j=0;j<m;j++){
                comb[j+1]=(comb[j]+prev[j]+curr[j])%MOD;
            }

            for(int j=0;j<m;j++){
                if(grid[i-1][j]=='#'){
                    next[j]=0;
                    continue;
                }
                int left=max(0,j-l);
                int right=min(m-1,j+l);
                next[j]=(comb[right+1]-comb[left]+MOD)%MOD;
            }

            prev=next;
            for(int j=0;j<m;j++) curr[j]=0;
        }

        ll ans=0;
        for(int j=0;j<m;j++) ans=(ans+curr[j]+prev[j])%MOD;

        return ans;
    }
};