class Solution {
public:
    string compressedString(string word) {
        if (word.empty()) return "";
        
        string comp;
        comp.reserve(word.size());
        
        #pragma GCC optimize("Ofast")
        #pragma GCC target("avx,avx2,fma")
        
        char ch = word[0];
        int cnt = 1;
        int n = word.size();
        
        for (int i = 1; i < n; i++) {
            if (__builtin_expect((word[i] == ch && cnt < 9), 1)) {
                cnt++;
            } else {
                comp += (cnt + '0');
                comp += ch;
                ch = word[i];
                cnt = 1;
            }
        }
        
        comp += (cnt + '0');
        comp += ch;
        
        return move(comp);
    }
};