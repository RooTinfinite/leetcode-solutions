class Solution {
public:
    using ll = long long;
    ll dp[20][2][150][2][2][10]; // id,tight,sum,inc,dec,prev 
    bool f(int n){
        if(n < 10) return true;
        vector<int>dig;
        while(n > 0){
            dig.push_back(n%10);
            n /= 10;
        }
        bool inc = true,dec = true;
        int prev = dig[0];
        for(int i = 1; i < dig.size(); i++){
            if(dig[i] > dig[i - 1]) dec = false;
            else if(dig[i] < dig[i - 1]) inc = false;
            else{
                inc = false;
                dec = false;
            }
        }
        return inc || dec;
    }
    ll solve(string &s,int id,bool tight,int sum,bool inc,bool dec,int prev){
        if(id == s.size()){
            if(inc||dec || f(sum)) return 1;
            return 0;
        }
        if(dp[id][tight][sum][inc][dec][prev] != -1) return dp[id][tight][sum][inc][dec][prev];
        int limit = tight ? s[id] - '0' : 9;
        ll ans = 0;
        for(int i = 0; i <= limit; i++){
            bool ntight = (tight && (i == limit));
            bool ninc = inc,ndec = dec;
            if((sum == 0 and i == 0) or (sum == 0 and i > 0)){
                ninc = 1,ndec = 1;
            }
            else {
                ninc = (inc and i > prev);
                ndec = (dec and i < prev);
            }
            ans += solve(s,id+1,ntight,sum+i,ninc,ndec,i);
        }
        return dp[id][tight][sum][inc][dec][prev] = ans;
    }
    long long countFancy(long long l, long long r) {
        //fancy mtlb => stricly inc or dec...
        //all num till r - all till l - 1
        string s = to_string(r);
        memset(dp,-1,sizeof(dp));
        ll ans1 = solve(s,0,1,0,1,1,0);
        if(l == 0) return ans1;
        s = to_string(l - 1);
        memset(dp,-1,sizeof(dp));
        return ans1 - solve(s , 0 , 1,0,1,1,0);
    }
};