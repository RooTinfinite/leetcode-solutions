class Solution {
public:
    string compressedString(string word) {
        string c;
        c.reserve(word.size());
        
        char ch = word[0];
        int cnt = 1;
        
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == ch && cnt < 9) {
                cnt++;
            } else {
                c += (cnt + '0');
                c += ch;
                ch = word[i];
                cnt = 1;
            }
        }
        
        c += (cnt + '0');
        c += ch;
        
        return c;
    }
};
