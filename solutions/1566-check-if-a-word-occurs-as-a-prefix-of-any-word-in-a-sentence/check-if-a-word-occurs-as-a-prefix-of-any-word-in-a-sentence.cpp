#include <string>
using namespace std;

class Solution {
public:

    bool fact(string t, string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        int word = 0;

        for (int i = 0; i < sentence.size(); i++) {
            string t = "";
            while (i < sentence.size() && sentence[i] != ' ') {
                t += sentence[i];
                i++;
            }
            word++;
            if (fact(t, searchWord)) {
                return word;
            }
        }
        return -1;
    }
};