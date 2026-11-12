class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.length();
        vector<int>nexta(n,n);
        vector<int>nextb(n,n);
        vector<int>nextc(n,n);
        int preva = n;
        int prevb = n;
        int prevc = n;

        for(int i=n-1;i>=0;i--){
            if(s[i] == 'a'){
                preva = i;
            }
            nexta[i] = preva;

            if(s[i] == 'b'){
                prevb = i;
            }
            nextb[i] = prevb;

            if(s[i] == 'c'){
                prevc = i;
            }
            nextc[i] = prevc;
        }

        long long ans = 0;

        for(int i=0;i<n;i++){
            int na = n;
            int nb = n;
            int nc = n;
            if(nexta[i] != n){
                na = nexta[i];
            }
            if(na < n){
                if(nextb[na] != n){
                    nb = nextb[na];
                }
            }

            if(nb < n){
                if(nextc[nb] != n){
                    nc = nextc[nb];
                }
            }
            if(nc >= n){
                ans += n-i;
            }else{
                ans += nc-i;
            }
        }
        return ans;
    }
};