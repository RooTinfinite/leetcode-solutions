class Solution {
public:
    int power(int a,int n,int mod)
    {
        long long res=1;
        while(n>0)
        {
            if(n%2!=0)
                res=((long long)res*a)%mod;
            n=n>>1;
            a=((long long)a*a)%mod;
        }
        return res;
    }
    vector<int> getGoodIndices(vector<vector<int>>& v, int t) {
        int n=v.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int k=power(power(v[i][0],v[i][1],10),v[i][2],v[i][3]);
            if(k==t)
                ans.push_back(i);
        }
        return ans;
    }
};