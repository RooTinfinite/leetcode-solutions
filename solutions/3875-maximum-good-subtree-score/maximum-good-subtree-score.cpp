class Solution {
public:
    int mod = 1e9 + 7;
    int ans = 0;
    // int dp[1501][1024];
    bool check(int n , int freq){
        while(n){
            int x = n%10;
            if(freq & 1<<x) return 0;
            freq |= 1<<x;
            n/=10;
        }
        return 1;
    }
   int give(int i ,vector<int>&nums,int freq,vector<vector<int>>&dp){
       if(i >= nums.size()) return 0;
       if(dp[i][freq] != -1) return dp[i][freq];
       int nottake = give(i+1,nums,freq,dp);
       int take = 0;
       if(check(nums[i],freq)){
           int newFreq = freq;
           int x = nums[i];
           while(x){
               int y = x%10;
               newFreq |= 1<<y;
               x/=10;
           }
           take = nums[i] + give(i+1,nums,newFreq,dp);
       }
       return dp[i][freq] = max(take,nottake);
   }
    vector<int> dfs(int node , vector<int>&v,vector<int>&vals,vector<vector<int>>&adj){
        vector<int>togive;
        for(auto i:adj[node]){
            vector<int> child = dfs(i,v,vals,adj);
            togive.insert(togive.end() , child.begin() , child.end());
        }
        togive.push_back(vals[node]);
        // v.push_back(vals[node]);
         vector<vector<int>> dp(togive.size()+1, vector<int>(1025, -1));
        int temp = give(0,togive,0,dp);
        ans += temp;
        ans %= mod;
        return togive;
    }
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        int n = par.size();
        // memset(dp,-1,sizeof(dp));
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[par[i]].push_back(i);
        }
        vector<int>v;
         dfs(0,v,vals,adj);
        return ans;
    }
};