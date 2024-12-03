class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int i = 0;
        
        for (int space : spaces) {
            result += s.substr(i, space - i) + " ";
            i = space;
        }
        
        result += s.substr(i);
        return result;
    }
};