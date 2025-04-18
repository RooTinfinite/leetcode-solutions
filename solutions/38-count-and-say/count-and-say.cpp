class Solution {
public:
    string countAndSay(int n) {
        string currentString = "1";
        for (int i = 2; i <= n; i++) {
            string nextString;
            for (int j = 0, k = 0; j < currentString.size(); j = k) {
                while (k < currentString.size() &&
                       currentString[k] == currentString[j])
                    k++;
                nextString += to_string(k - j) + currentString[j];
            }
            currentString = nextString;
        }
        return currentString;
    }
};