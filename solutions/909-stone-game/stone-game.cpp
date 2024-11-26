class Solution {
public:
   int find(int s,int e,bool turn,vector<int>&piles,int &a,int &b,vector<vector<int>>&dp){
         //baes case:
             if(s>e) return 0;
             if(dp[s][e]!=-1) return dp[s][e];
         if(turn){
           a= max(piles[s]+find(s+1,e,false,piles,a,b,dp),piles[e]+find(s,e-1,false,piles,a,b,dp));
           return dp[s][e]=a;
         }
         else{
           b= max(piles[s]+find(s+1,e,true,piles,a,b,dp),piles[e]+find(s,e-1,true,piles,a,b,dp));
           return dp[s][e]=b;

         }
         return 0;
   }        

    bool stoneGame(vector<int>& piles) {
        int a=0,b=0;
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        find(0,piles.size()-1, true,piles,a,b,dp);
        cout<<a<<" "<<b<<endl;
        return a>b;  
    }
};