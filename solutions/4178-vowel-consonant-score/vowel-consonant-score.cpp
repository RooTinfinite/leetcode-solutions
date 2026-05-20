class Solution {
public:
    static int vowelConsonantScore(string& s) {
        constexpr unsigned vowMask=1|(1<<('e'-'a'))|(1<<('i'-'a'))|(1<<('o'-'a'))|(1<<('u'-'a'));
        int C=0, V=0;
        for(int c: s){
            if(c<'a' || c>'z') continue;
            bool isV=((1<<(c-'a'))& vowMask)!=0;
            V+=isV;
            C+=1-isV;
        }
        return C==0? 0:V/C;
    }
};