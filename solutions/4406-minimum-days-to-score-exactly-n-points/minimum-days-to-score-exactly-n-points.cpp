class Solution {
public:
    int minDays(int n) {

        vector<int> dp( n+1 , INT_MAX ) ;
        dp[0] = 0 ;

        for ( int score = 1 ; score <= n ; score++ ) {

            long long sum = 0 ;

            for ( int k = 1 ; k <= score ; k++ ) {

                sum += k ;

                if ( sum > score ) break ;

                int remaining = score - sum ;

                if ( remaining == 0 ) dp[score] = min( dp[score] , k ) ;

                else if ( dp[remaining] != INT_MAX ) 
                dp[score] = min( dp[score] , dp[remaining]+k+1 ) ;
                
            }
        }

        return dp[n] ;
        
    }
};