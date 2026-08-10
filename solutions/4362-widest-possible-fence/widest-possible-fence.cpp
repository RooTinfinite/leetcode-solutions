class Solution {
public:
    int maximumWidth(vector<int>& planks) {

        typedef long long ll ;

        unordered_map<ll,int> freq,mpp ;

        // storing frequency of every number
        for ( auto it : planks ) freq[it]++ ;

        // storing number & its frequency in vector bcz in map we cant access elements by index
        vector<pair<ll,int>> vec(freq.begin(), freq.end());

        // single plank contribute exactly its frequency to width
        for ( auto it : vec ) mpp[it.first] = it.second ;

        int n = vec.size() ;

        for ( int i = 0 ; i < n ; i++ ) {

            for ( int j = i ; j < n ; j++ ) {

                ll value = vec[i].first + vec[j].first ;

                // if ( i == j ) means we are adding same number , so width = frequnecy / 2
                if ( i == j ) mpp[value] += vec[i].second / 2 ;

                // if i != j then different number hai then , width = min of both value
                else mpp[value] += min( vec[i].second , vec[j].second ) ;
                
             }

        } 

        int ans = 1 ;

        // finding maximum width
        for ( auto it : mpp ) ans = max( ans , it.second ) ;

        return ans ;
        
    }
};