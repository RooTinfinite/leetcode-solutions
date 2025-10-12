class Solution {
public:
    vector<int> findCoins(vector<int>& num) {
        int n=num.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(dp[i]!=num[i-1] && num[i-1]>0){
                ans.push_back(i);
                for(int j=i;j<=n;j++){
                    dp[j]+=dp[j-i];
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(num[i-1]!=dp[i]){
                return {};
            }
            
        }
        sort(ans.begin(),ans.end());
            return ans;
    }
};