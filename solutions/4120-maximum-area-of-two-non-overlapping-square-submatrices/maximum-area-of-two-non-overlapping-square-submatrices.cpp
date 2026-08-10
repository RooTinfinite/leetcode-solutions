class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size() ;
        int n = mat[0].size() ;

        vector<vector<int>> dp1(m, vector<int>(n, 0)) ; // forward dp
        vector<vector<int>> dp2(m, vector<int>(n, 0)) ; // backward dp

        vector<int> top(m, 0), bot(m,0), left(n, 0), rt(n, 0) ;

        // forward dp
        for( int i = 0 ; i<m ; i++ ){
            for( int j = 0 ; j<n ; j++ ){
                if( mat[i][j] ){
                    if( i==0 || j==0 ) dp1[i][j] = 1 ;
                    else dp1[i][j] = min({dp1[i-1][j], dp1[i][j-1], dp1[i-1][j-1]}) + 1 ;

                    top[i] = max(top[i], dp1[i][j]) ;
                    left[j] = max(left[j], dp1[i][j]) ;
                }
            }
        }

        // Carry the max values forward (Prefix Max)
        for( int i = 1 ; i<m ; i++ ) top[i] = max(top[i], top[i-1]) ;
        for( int j = 1 ; j<n ; j++ ) left[j] = max(left[j], left[j-1]) ;

        // backward dp
        for( int i = m-1 ; i>= 0 ; i-- ){
            for( int j = n-1 ; j>= 0 ; j-- ){
                if( !mat[i][j] ) continue ;
                
                if( i==m-1 || j==n-1 ) dp2[i][j] = 1 ;
                else dp2[i][j] = min({dp2[i+1][j], dp2[i][j+1], dp2[i+1][j+1]}) + 1 ;

                bot[i] = max(bot[i], dp2[i][j]) ;
                rt[j] = max(rt[j], dp2[i][j]) ;
            }
        }

        // Carry the max values backward (Suffix Max)
        for( int i = m-2 ; i>=0 ; i-- ) bot[i] = max(bot[i], bot[i+1]) ;
        for( int j = n-2 ; j>=0 ; j-- ) rt[j] = max(rt[j], rt[j+1]) ;

        // assume partioning... at row i, & then at col j
        int mx_k = 0 ;
        for( int i = 0 ; i<m-1 ; i++ ){
            mx_k = max(mx_k, min(top[i], bot[i+1])) ;
        }
        for( int j = 0 ; j<n-1 ; j++ ){
            mx_k = max(mx_k, min(left[j], rt[j+1])) ;
        }

        return mx_k*mx_k ;
    }
};