class Solution {
public:
    bool scoreBalance(string s) {
        int t=0;
        for(auto it:s){
         t+=it-'a'+1;
        }
        if(t%2) return false;
        int curr=0;
        t=t/2;
        for(auto it:s){

            curr+=it-'a'+1;
            if(curr==t) return true;
        }
        return false;
    }
};