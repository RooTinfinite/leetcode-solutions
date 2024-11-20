class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> d(3);
        for (char c : s) d[c - 'a']++;
        for (int i = 0; i < 3; i++) {
            d[i] -= k;
            if (d[i] < 0) return -1;
        }
        
        vector<int> h(3);
        int m = 0, l = 0;
        
        for (int r = 0; r < s.length(); r++) {
            h[s[r] - 'a']++;
            while (h[s[r] - 'a'] > d[s[r] - 'a']) {
                h[s[l] - 'a']--;
                l++;
            }
            m = max(m, r - l + 1);
        }
        
        return s.length() - m;
    }
};