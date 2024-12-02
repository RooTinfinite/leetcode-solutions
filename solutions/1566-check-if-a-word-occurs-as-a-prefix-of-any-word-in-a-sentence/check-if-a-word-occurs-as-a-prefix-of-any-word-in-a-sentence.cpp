class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i = -1;
        int wordPos = 0;
        do {
            ++i;
            ++wordPos;
            if(sentence.substr(i, searchWord.size()) == searchWord) {
                return wordPos;
            }
        } while((i = sentence.find(' ', i)) != string::npos);
        return -1;
    }
};