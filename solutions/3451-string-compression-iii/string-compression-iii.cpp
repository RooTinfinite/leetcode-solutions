class Solution {
public:
    string compressedString(string word) {
        if (word.empty()) return "";
        
        string comp;
        comp.reserve(word.size() * 2);  // Maximum possible size
        
        char ch = word[0];
        int cnt = 1;
        
        #pragma unroll
        for (int i = 1; i < word.size(); ++i) {
            if (word[i] == ch && cnt < 9) {
                ++cnt;
            } else {
                comp += (cnt + '0');
                comp += ch;
                ch = word[i];
                cnt = 1;
            }
        }
        
        comp += (cnt + '0');
        comp += ch;
        
        return comp;
    }
};