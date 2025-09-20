class Solution {
    bool isPalindrome(string s){
        int i=0, j=s.size();
        while(i<=j){
           if(s[i++]!=s[j--]) return false;
        }
        return true;
    }

    string convert(int n, int base) {
        string res = "";
        while (n > 0) {
            int remainder = n % base;
            char digit;
            if (remainder < 10) digit = '0' + remainder;
            else digit = 'A' + (remainder - 10); // for base > 10
            res += digit;
            n /= base;
        }
        reverse(res.begin(), res.end());
        return res;
    }

public:
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++){
            string temp = convert(n , i);
            if( ! isPalindrome(temp)){
                return false;
                break;
            }else{
                continue;
            }

        }
        return true;
    }
};