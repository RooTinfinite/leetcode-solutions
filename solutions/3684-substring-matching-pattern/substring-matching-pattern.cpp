class Solution {
public:
    bool hasMatch(string s, string p) {
        
        size_t starPos = p.find('*');
        string head = p.substr(0, starPos);
        string tail = p.substr(starPos + 1);

        size_t left = s.find(head);
        size_t rght = s.rfind(tail);

        if (left == string::npos || rght == string::npos) return false;
        return left + head.length() <= rght;}
};