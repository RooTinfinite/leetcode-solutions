class Solution {
public:
    string toHex(int num) {
        string hexas = "0123456789abcdef";
        
        if (num == 0) return "0";
        if (num > 0 && num <= 15) return string(1, hexas[num]);
        
        unsigned int n = num;
        string result = "";
        
        while (n > 0) {
            result = hexas[n % 16] + result;
            n /= 16;
        }
        
        return result;
    }
};