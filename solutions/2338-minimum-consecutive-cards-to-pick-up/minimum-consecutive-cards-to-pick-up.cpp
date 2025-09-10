class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size() ;  
        unordered_map<int, int> mp ;
        int res = INT_MAX ;

        for(int i=0; i<n; i++){
            if( mp.find(cards[i]) != mp.end() ){
                res = min(res, i - mp[cards[i]] + 1 );
            }
            mp[cards[i]] = i ;
        }
        if(res==INT_MAX) return -1 ;
        return res ;
    }
};