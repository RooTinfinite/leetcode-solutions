class Solution {
public:
    int isPrefixOfWord(string sentence, string w) {
        stringstream ss(sentence);
        string t;
        for(int i = 1; ss >> t; i++)
            if(t.substr(0, w.length()) == w) return i;
        return -1;
    }
};