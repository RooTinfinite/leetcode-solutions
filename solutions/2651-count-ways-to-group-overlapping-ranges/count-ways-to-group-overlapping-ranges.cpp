class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
       
        long long ans = 1;
        
        sort( ranges.begin() , ranges.end());
    
        int end   = ranges[0][1];
        
        int mod = 1e9 + 7 ;
        
        
        for( int i = 1 ; i < ranges.size() ; i++)
        {
            if( ranges[i][0] <= end)
            {
                 end = max( end , ranges[i][1] );
            }
            else
            {
                ans= (( ans%mod )*( 2 % mod )) %mod;
                end = max( end , ranges[i][1]);
            }
        }

        ans= (( ans%mod )*( 2 % mod )) %mod;
        
        return ans;
    
    }
};