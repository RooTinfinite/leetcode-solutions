class Solution {
public:
    int numWays(string s) 
    {
        long long mod=1e9+7;
        long n=s.size();
        int one=count(s.begin(),s.end(),'1');
        if(one%3)
            return 0;
        if(!one)
            return (((n-1)*(n-2))/2)%mod;
        one/=3;
        long cnt=0,z1=0,z2=0;
        for(auto c :s)
        {
         if(c=='1')
             cnt++;
            if(cnt==one)
                z1++;
            else if(cnt==2*one)
                z2++;
                
        }
        return (z1*z2)%mod;
    }
};