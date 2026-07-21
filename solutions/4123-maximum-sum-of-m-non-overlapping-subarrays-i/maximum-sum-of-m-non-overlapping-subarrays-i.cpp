class Solution {
public:
    long long maximumSum(vector<int>& v, int m, int l, int r) {
        int n=v.size();
        long long inf=1e15;
        vector<vector<long long>>dp(m+5,vector<long long>(n+5,-inf));
        vector<long long>sum(n+5,0);
        sum[0]=v[0];
        for(int i=1;i<n;i++)sum[i]=sum[i-1]+1LL*v[i];
        deque<vector<long long>>q;
        for(int i=0;i<n;i++)dp[0][i]=0;
        long long ans=-inf;
        for(int j=1;j<=m;j++){
            while(q.size())q.pop_back();
            q.push_back({0,-1});
            dp[1][l-1]=sum[l-1];
            ans=max(ans,dp[1][l-1]);
            for(int i=l;i<n;i++){
                if(i)dp[j][i]=dp[j][i-1];
                if(i>=l){
                    long long val=-sum[i-l]+dp[j-1][i-l];
                    while(q.size()&&q.back()[0]<=val)q.pop_back();
                    q.push_back({val,i-l+1});
                }
                while(q.size()){
                    int idx=q.front()[1];
                    if(i>=r+1&&idx<=i-r)q.pop_front();
                    else if(i>=r&&idx==-1)q.pop_front();
                    else break;
                }
                if(q.size()){
                    dp[j][i]=max(dp[j][i],sum[i]+q.front()[0]);
                }
                ans=max(ans,dp[j][i]);
            }
        }
        return ans;
    }
};