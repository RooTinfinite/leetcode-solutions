class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int cnt[26] = {0};
        
        for (int i = 0; i < word1.size(); i++) {
            cnt[word1[i] - 'a']++;
            cnt[word2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (abs(cnt[i]) > 3) {
                return false;
            }
        }
        
        return true;
    }
};