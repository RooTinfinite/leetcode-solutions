class Solution {
public:
    string compressedString(string word) {
        // Handle empty string case
        if (word.empty()) return "";
        
        // Initialize result string with reserved capacity to avoid reallocations
        string comp;
        comp.reserve(word.size() * 2);
        
        // Initialize counter and first character
        int cnt = 1;                // Tracks consecutive occurrences of current character
        char ch = word[0];         // Current character being counted
        
        // Iterate through string starting from second character
        for (size_t i = 1; i < word.size(); ++i) {
            // If current character matches previous and count < 9
            // increment counter
            if (word[i] == ch && cnt < 9) {
                ++cnt;
            } 
            // If character changes or count reaches 9
            // append count and character to result
            else {
                comp += (cnt + '0');    // Convert count to character and append
                comp += ch;             // Append the character
                ch = word[i];           // Update current character
                cnt = 1;                // Reset counter for new character
            }
        }
        
        // Handle the last group of characters
        comp += (cnt + '0');    // Append final count
        comp += ch;             // Append final character
        
        return comp;
    }
};