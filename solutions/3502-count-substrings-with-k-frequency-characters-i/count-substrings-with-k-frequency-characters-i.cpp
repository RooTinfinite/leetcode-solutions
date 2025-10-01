class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;
        int l = 0;
        unordered_map<char, int> d;
        
        for (char c : s) {
            d[c]++;
            while (d[c] == k) {
                d[s[l]]--;
                l++;
            }
            ans += l;
        }
        
        return ans;
    }
};