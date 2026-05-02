int dp[7][2][2];
array<char, 7> mirrow={0,1,2,5,6,8,9};
class Solution {
public:
    static int  f(int i, bool tight, bool has2569, string& s){
        if (i==6) return has2569;
        if (dp[i][tight][has2569]!=-1) return dp[i][tight][has2569];
        int cnt=0;

        int lim=tight?(s[i]-'0'):9;

        for(int d: mirrow){
            if (d>lim) break;
            bool nxtTight=tight & (d==lim);
            switch(d){
                case 2: case 5: case 6: case 9:
                    cnt+=f(i+1, nxtTight, 1, s); break;
                case 0: case 1: case 8:
                    cnt+=f(i+1, nxtTight, has2569, s); break;
            }
        }
        return dp[i][tight][has2569]=cnt;
    }
    static inline string toS(int n){
        string s(6, '0');
        for(int x=n, i=5; x; x/=10, i--){
            s[i]='0'+x%10;
        }
        return s;
    }
    static int rotatedDigits(int n) {
        string s=toS(n);
        memset(dp, -1, sizeof(dp));
        return f(0, 1, 0, s);
    }
};