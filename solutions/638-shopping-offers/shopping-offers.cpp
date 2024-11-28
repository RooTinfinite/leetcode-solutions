struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t result = 0;
        for (int i : v) {
            result ^= hasher(i) + 0x9e3779b9 + (result << 6) + (result >> 2);
        }
        return result;
    }
};
class Solution {
public:
    int solve(vector<int>& p, vector<vector<int>>& s, vector<int>& n,int idx, unordered_map<vector<int>,int,VectorHash>&dp){
        if(idx>=p.size())return 0;
        if(n[idx]==0) return solve(p,s,n,idx+1,dp);

        if(dp.count(n))return dp[n];
        int cnt = 0;
        int spick=100000,norpick=100000;
        for(int i=0;i<s.size();i++){
            cnt=1;
            for(int j=0;j<n.size();j++){
                if(s[i][j]>n[j]){
                    cnt=0;
                    break;
                }
            }
            if(cnt==1){
                int k = p.size();
                int spick2 =  s[i][k];
                for(int j=0;j<k;j++) n[j]-=s[i][j];
                if(n[idx]==0) spick2 += solve(p,s,n,idx+1,dp);
                else spick2+=solve(p,s,n,idx,dp);
                for(int j=0;j<k;j++) n[j]+=s[i][j];
                spick=min(spick2,spick);
            }
        }
        if(cnt==0){
            norpick = p[idx]*n[idx];
            int val = n[idx];
            n[idx]=0;
            norpick+=solve(p,s,n,idx+1,dp);
            n[idx]=val;
        }
        else {
            norpick = p[idx];
            n[idx]-=1;
            if(n[idx]==0)norpick+=solve(p,s,n,idx+1,dp);
            else norpick+=solve(p,s,n,idx,dp);
            n[idx]+=1;
        }
        return dp[n]=min(norpick,spick);

    }
    int shoppingOffers(vector<int>& p, vector<vector<int>>& s, vector<int>& n) {
        unordered_map<vector<int>,int,VectorHash>dp;
        return solve(p,s,n,0,dp);
    }
};