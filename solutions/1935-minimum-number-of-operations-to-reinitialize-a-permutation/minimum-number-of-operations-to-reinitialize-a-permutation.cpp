class Solution {
public:
    int reinitializePermutation(int n) {
        int res = 0;
        for(int i = 1; i > 1 || res == 0; ++res){
            if(i < n / 2) i <<= 1;
            else i = (i - n / 2) * 2 + 1;
        }
        return res;
    }
};