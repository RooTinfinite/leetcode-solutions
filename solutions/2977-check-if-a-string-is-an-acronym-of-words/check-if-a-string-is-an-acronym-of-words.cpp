class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string ac = "";

        for(int i=0;i<words.size();i++){
            ac += words[i][0];
        }

        return s == ac;
    }
};