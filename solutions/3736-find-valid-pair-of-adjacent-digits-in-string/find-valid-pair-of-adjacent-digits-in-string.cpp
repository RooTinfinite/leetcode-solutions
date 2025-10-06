class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> ctr;
        for (char c : s) {
            ctr[c]++;}

        unordered_set<char> valid;
        for (auto& p : ctr) {
            char digit = p.first;

            if (p.second == digit - '0') {
                valid.insert(digit);}}

        for (size_t i = 0; i < s.size() - 1; i++) {
            char digit1 = s[i];
            char digit2 = s[i + 1];
            if (digit1 == digit2) continue;
            if (valid.count(digit1) && valid.count(digit2)) {
                return string() + digit1 + digit2;} }
        
        return "";}};