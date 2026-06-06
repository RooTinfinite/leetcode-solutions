using ll = long long;
int vis[101][101][101]; 
ll dp[101][101][101];
int timer=0;  
class Solution {
private:
    
    ll rec(int k,int i,int j, vector<int> &nums1, vector<int> &nums2){
        if(!k) return 0; 
        if(i<0 || j<0){
           return -1e16; 
        }
 
        if(vis[k][i][j]==timer) return dp[k][i][j]; 
        if(i+1<k || j+1<k ) return -1e16;  
        
        ll ans=-1e16; 
        ans=max({
            ans,1LL*nums1[i]*nums2[j]+rec(k-1,i-1,j-1,nums1,nums2),
            rec(k,i-1,j,nums1,nums2),
            rec(k,i,j-1,nums1,nums2)
        }); 
        vis[k][i][j]=timer ;
        return dp[k][i][j]=ans; 
        
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(); 
        int m=nums2.size(); 
        timer++; 
       return  rec(k,n-1,m-1,nums1,nums2);
        
    }
};