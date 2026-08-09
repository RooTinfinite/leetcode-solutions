class Solution {
public:
    int mod = 1e9+7 ;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size() ;
        
        // forward pass where i count opern for <a
        int ans = 0 ;
        int ind_a = 0 ;
        for( int i = 0 ; i<n ; i++ ){
            if( nums[i] < a ){
                ans = (ans + i-ind_a)%mod ;
                ind_a++ ;
            }
        }

        // backward pass where i count opern for >b
        int ind_b = n-1 ;
        for( int i = n-1 ; i>=0 ; i-- ){
            if( nums[i]<a ) ind_b-- ;
            if( nums[i]>b ){
                ans = (ans + ind_b-i)%mod ;
                ind_b-- ;
            }
        }
        return ans ;
    }
};