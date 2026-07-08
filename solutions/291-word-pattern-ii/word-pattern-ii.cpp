class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, string> symbolMap;
        unordered_set<string> wordSet;

        return isMatch(s, 0, pattern, 0, symbolMap, wordSet);
    }

private:
    bool isMatch(string& s, int sIndex, string& pattern, int pIndex,
                 unordered_map<char, string>& symbolMap,
                 unordered_set<string>& wordSet) {
        // Base case: reached end of pattern
        if (pIndex == pattern.length()) {
            return sIndex == s.length(); // True iff also reached end of s
        }

        // Get current pattern character
        char symbol = pattern[pIndex];

        // This symbol already has an associated word
        if (symbolMap.find(symbol) != symbolMap.end()) {
            string word = symbolMap[symbol];
            // Check if it matches s[sIndex...sIndex + word.length()]
            if (s.compare(sIndex, word.length(), word)) {
                return false;
            }
            // If it matches continue to match the rest
            return isMatch(s, sIndex + word.length(), pattern, pIndex + 1,
                           symbolMap, wordSet);
        }

        // This symbol does not exist in the map
        for (int k = sIndex + 1; k <= s.length(); k++) {
            string newWord = s.substr(sIndex, k - sIndex);
            if (wordSet.find(newWord) != wordSet.end()) {
                continue;
            }
            // Create or update it
            symbolMap[symbol] = newWord;
            wordSet.insert(newWord);
            // Continue to match the rest
            if (isMatch(s, k, pattern, pIndex + 1, symbolMap, wordSet)) {
                return true;
            }
            // Backtracking
            symbolMap.erase(symbol);
            wordSet.erase(newWord);
        }
        // No mappings were valid
        return false;
    }
};