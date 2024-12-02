class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        stringstream ss(s);
        string t;
        for(int i = 1; ss >> t; i++)
            if(t.substr(0, w.length()) == w) return i;
        return -1;
    }
};