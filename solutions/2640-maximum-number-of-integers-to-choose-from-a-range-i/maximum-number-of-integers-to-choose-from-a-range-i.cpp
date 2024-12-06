class Solution {
public:
    int maxCount(vector<int>& b, int n, int m) {

        vector<int> mp(1e4+1,1);
        for(auto it:b)mp[it]=0;

        int ans=0;

        for(int i=1;i<=n;i++){
            if(mp[i]==0)continue;
            if(m>=i){
                ans++;
                m-=i;
                mp[i]=0;
            }
        }

        return ans; 
    }
};