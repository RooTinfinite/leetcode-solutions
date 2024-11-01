class Solution {
private:
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
    vector<string> output;
    
    void backtrack(string combination, string next_digits) {
        if (next_digits.empty()) {
            output.push_back(combination);
        } else {
            for (char letter : phone_map[next_digits[0]]) {
                backtrack(combination + letter, next_digits.substr(1));
            }
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        output.clear();
        backtrack("", digits);
        return output;
    }
};