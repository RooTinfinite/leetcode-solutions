class Solution {
public:
    string compressedString(string word) {
        if (word.empty()) return "";
        
        string comp;
        comp.reserve(word.length()); // Pre-allocate memory
        
        int count = 1;
        char current = word[0];
        
        for (size_t i = 1; i < word.length(); ++i) {
            if (word[i] == current && count < 9) {
                count++;
            } else {
                comp += to_string(count) + current;
                current = word[i];
                count = 1;
            }
        }
        
        comp += to_string(count) + current;
        return comp;
    }
};