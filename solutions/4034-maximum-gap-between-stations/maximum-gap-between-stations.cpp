class Solution {
public:
    int maximumGap(string skill, string station) {

        int n = skill.size() ;
        int m = station.size() ;

        vector<int> left( n , 0 ) , right( n , 0 ) ;

        int j = 0 ;

        // placing workers as early as possible
        for ( int i = 0 ; i < n ; i++ ) {

            while ( skill[i] != station[j] ) j++ ;

            left[i] = j ;
            j++ ;
            
        }

        // placing workers as late as possible
        j = m-1 ;

        for ( int i = n-1 ; i >= 0 ; i-- ) {

            while( skill[i] != station[j] ) j-- ;

            right[i] = j;
            j-- ;
            
        }

        int ans = 0 ;

        for ( int i = 0 ; i < n-1 ; i++ ) {

            // ans = max_position - min_position 
            ans = max( ans , right[i+1] - left[i] ) ;
            
        }

        return ans ;
        
    }
};