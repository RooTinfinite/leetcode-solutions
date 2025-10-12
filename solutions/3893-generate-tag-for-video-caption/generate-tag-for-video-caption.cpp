class Solution {
public:
    string generateTag(string caption) {
        int start = caption.find_first_not_of(' ');
        if (start == string::npos) return "#";
        string res = "#";
        bool makeNxtUpperCase = false;
        bool isFirstChar = true;

        for (int i = start; i < caption.length() && res.length() < 100; i++) {
            char ch = caption[i];
            if (!isalpha(ch)) {
                if (ch == ' ') makeNxtUpperCase = true;
                continue;
            }

            if (isFirstChar) {
                res += tolower(ch);
                isFirstChar = false;
            }
            else if (makeNxtUpperCase) {
                res += toupper(ch);
                makeNxtUpperCase = false;
            }
            else res += tolower(ch);
        }
        return res;
    }
};