class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {

        int maxi = *max_element( lights.begin() , lights.end() ) ;

        int penalty = 0 ;

        int n = arrivalTime.size() ;

        for ( int i = 0 ; i < n ; i++ ) {

            int r = arrivalTime[i] % period ;

            if ( r < maxi ) penalty = max(penalty,0) ;

            else penalty = max(penalty,period-r) ;
            
        }

        return penalty ;
        
    }
};