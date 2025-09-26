class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int count = 0;

        for (int i = 1; i <= word.length() / k; i++) {
            count = i;
            if (word.substr(k * i) == word.substr(0, word.length() - k * i)) {
                return i;
            }
        }

        return count + 1;        
    }
};