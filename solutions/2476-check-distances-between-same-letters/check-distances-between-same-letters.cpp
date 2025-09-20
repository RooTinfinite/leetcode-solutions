class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int alpha[26];
        fill_n(alpha, 26, -1);
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (alpha[idx] != -1) {
                if (i - alpha[idx] - 1 != distance[idx]) return false;
            } 
            else alpha[idx] = i;
        }
        return true;
    }
};