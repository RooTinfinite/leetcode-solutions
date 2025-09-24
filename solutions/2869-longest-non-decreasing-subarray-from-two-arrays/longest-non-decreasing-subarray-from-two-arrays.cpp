class Solution {
public:
    int maxNonDecreasingLength(vector<int>& v1, vector<int>& v2) {
        int n=v1.size();
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);
        int ans=1;
        for(int i=1;i<n;i++)
        {
            if(v1[i]>=v1[i-1])
                dp1[i]=max(dp1[i],1+dp1[i-1]);
            if(v1[i]>=v2[i-1])
                dp1[i]=max(dp1[i],1+dp2[i-1]);
            if(v2[i]>=v1[i-1])
                dp2[i]=max(dp2[i],1+dp1[i-1]);
            if(v2[i]>=v2[i-1])
                dp2[i]=max(dp2[i],1+dp2[i-1]);
            ans=max(ans,max(dp1[i],dp2[i]));
        }
        return ans;
    }
};