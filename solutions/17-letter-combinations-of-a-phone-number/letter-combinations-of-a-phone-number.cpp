class Solution {
private:
    // Map each digit to corresponding letters on phone keypad
    unordered_map<char, string> phone_map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    // Vector to store all generated combinations
    vector<string> output;
    
    // Recursive backtracking function
    // combination: current built string
    // next_digits: remaining digits to process
    void backtrack(string combination, string next_digits) {
        // Base case: if no more digits to process
        if (next_digits.empty()) {
            // Add completed combination to result vector
            output.push_back(combination);
        } else {
            // Get all letters for current digit
            // next_digits[0] gets first digit from remaining digits
            string letters = phone_map[next_digits[0]];
            
            // Try each letter for current digit
            for (char letter : phone_map[next_digits[0]]) {
                // Add current letter to combination
                // Remove first digit using substr(1)
                // Recursively process remaining digits
                backtrack(combination + letter, next_digits.substr(1));
            }
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        // Handle empty input case
        if (digits.empty()) {
            return {};
        }
        
        // Clear output vector for fresh calculation
        output.clear();
        
        // Start backtracking with empty combination
        backtrack("", digits);
        
        // Return all generated combinations
        return output;
    }
};