class Solution {
public:
    int numSub(string s) {
        int M = 1e9+7, n=s.size() ;
        long long count = 0 ;

        int curr = 0 ;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                curr++; 
            }
            else{
                count+=((long long)curr*(curr+1))/2L;
                curr=0;
            }
        }
        count+=((long long)curr*(curr+1))/2L;
                
        return count%M;
    }
};