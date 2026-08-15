class Solution {
public:
    int minOperations(string s) {

        int n = s.size() ;
        int ans = INT_MAX ;

        for ( int r = 0 ; r < n ; r++ ) {

            int ops = r ;

            for ( int i = 0 ; i < n/2 ; i++ ) {

                char left = s[(i+r)%n] ;
                char right = s[(n-1-i+r)%n] ;

                int f1 = (right-left+26) % 26 ;
                int f2 = (left-right+26) % 26 ;

                ops += min( f1 , f2 ) ;
                
            }

            ans = min( ans , ops ) ;
            
        }

        return ans ;
        
    }
};