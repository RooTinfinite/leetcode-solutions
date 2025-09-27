#define INCL()                                                                 \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    string lastNonEmptyString(string s) {
        INCL();

        int n = s.length();
        vector<int> freq(26, 0);

        for (char& ch : s)
            freq[ch - 'a']++;

        int maxFreq = *max_element(freq.begin(), freq.end());
        if (maxFreq == 1)
            return s;

        vector<bool> isMostRepeated(26, false);
        for (int i = 0; i < 26; i++) {
            if (freq[i] == maxFreq)
                isMostRepeated[i] = true;
        }

        string result = "";
        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            if (isMostRepeated[ch - 'a']) {
                result = ch + result;
                isMostRepeated[ch - 'a'] = false;
            }
        }

        return result;
    }
};