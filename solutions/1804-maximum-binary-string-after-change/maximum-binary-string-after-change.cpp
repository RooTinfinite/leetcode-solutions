class Solution {
public:
    string maximumBinaryString(string s) {
        int i = 0, countzero = 0;
        while (i < s.size() && s[i] == '1') i++;
        for (int j = i; j < s.size(); ++j) {
            if (s[j] == '0') countzero++;
            s[j] = '1';
        }
        if (countzero > 0) s[i + countzero - 1] = '0';
        return s;
    }
};