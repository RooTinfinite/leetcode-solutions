#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int openCounts = 0; // Tracks unmatched '('
        int insertions = 0; // Tracks required insertions

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openCounts++;
            } else if (i + 1 < s.size() && s[i + 1] == ')') {
                if (openCounts > 0) openCounts--;
                else insertions++;
                i++; // Skip the next ')'
            } else {
                if (openCounts > 0) {
                    openCounts--;
                    insertions++;
                } else {
                    insertions += 2;
                }
            }
        }

        return insertions + 2 * openCounts;
    }
};