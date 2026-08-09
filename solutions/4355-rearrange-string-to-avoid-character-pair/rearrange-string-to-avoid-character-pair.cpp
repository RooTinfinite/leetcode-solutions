class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string xc = "";
        string yc = "";
        string others = "";

        for (char c : s) {
            if (c == y) yc += c;
            else if (c == x) xc += c;
            else others += c;
        }
        
        return yc + others + xc;
    }
};
