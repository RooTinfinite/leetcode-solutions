class Solution {
private:
    static int mod1(int i, int n) {
        return i - ((-(i >= n ? 1 : 0)) & n);
    }
    
public:
    static vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        
        if (k < 0) {
            int s = 0;
            for (int i = n + k; i < n; i++) {
                s += code[i];
            }
            
            for (int i = 0; i < n; i++) {
                code[i] <<= 16;
            }
            
            for (int i = 0; i < n; i++) {
                int v = code[i] >> 16;
                code[i] += s;
                int j = mod1(n + k + i, n);
                s += v - (code[j] >> 16);
            }
            
            for (int i = 0; i < n; i++) {
                code[i] &= 0x3FFF;
            }
            
        } else if (k > 0) {
            int s = 0;
            for (int i = 0; i < k; i++) {
                s += code[i];
            }
            
            for (int i = 0; i < n; i++) {
                code[i] <<= 16;
            }
            
            for (int i = 0; i < n; i++) {
                int v = code[i] >> 16;
                int j = mod1(i + k, n);
                s += (code[j] >> 16) - v;
                code[i] += s;
            }
            
            for (int i = 0; i < n; i++) {
                code[i] &= 0x3FFF;
            }
            
        } else {
            fill(code.begin(), code.end(), 0);
        }
        
        return code;
    }
};