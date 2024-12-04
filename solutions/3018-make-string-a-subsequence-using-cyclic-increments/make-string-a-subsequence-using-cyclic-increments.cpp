class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if (str1.length() == str2.length()) {
            for (int i = 0; i < str1.length(); i++) {
                if (str2[i] == 'a' && str1[i] == 'z') {
                    continue;
                }
                else if (str1[i] == str2[i]) {
                    continue;
                }
                else if (str2[i] - str1[i] != 1) {
                    return false;
                }
            }
            return true;
        }
        
        if (str2.length() > str1.length()) {
            return false;
        }
        
        vector<char> l;
        for (char c : str2) {
            if (str1.find(c) == string::npos) {
                l.push_back(c);
            }
        }
        
        int count = 0;
        for (char c : l) {
            if (str1.find(char(c - 1)) != string::npos) {
                count++;
            }
            if (c == 'a' && str1.find('z') != string::npos) {
                count++;
            }
        }
        
        return count == l.size();
    }
};