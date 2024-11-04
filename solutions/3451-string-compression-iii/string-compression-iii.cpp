class Solution {
public:
    string compressedString(string word) {
        if (word.empty()) return "";
        
        // Pre-allocate memory to avoid reallocations
        string comp;
        comp.reserve(word.size() * 2);
        
        int cnt = 1;
        char ch = word[0];
        
        for (size_t i = 1; i < word.size(); ++i) {
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