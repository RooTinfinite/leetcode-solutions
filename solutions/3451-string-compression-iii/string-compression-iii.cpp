class Solution {
public:
    string compressedString(string word) {
        if (word.empty()) {
            return "";
        }
        
        vector<string> comp;
        char currentChar = word[0];
        int count = 1;
        
        for (int i = 1; i < word.length(); i++) {
            if (word[i] == currentChar) {
                if (count == 9) {
                    comp.push_back("9");
                    comp.push_back(string(1, currentChar));
                    count = 1;
                } else {
                    count++;
                }
            } else {
                comp.push_back(to_string(count));
                comp.push_back(string(1, currentChar));
                currentChar = word[i];
                count = 1;
            }
        }
        
        // Append the last run
        comp.push_back(to_string(count));
        comp.push_back(string(1, currentChar));
        
        string result;
        for (const string& s : comp) {
            result += s;
        }
        
        return result;
    }
};