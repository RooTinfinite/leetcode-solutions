class Solution {
public:
    int maxDistinct(string s) {
        vector<bool> seen(26, false);
        int cnt = 0;
        for (char ch : s) {
            int idx = ch - 'a';
            if (!seen[idx]) {
                seen[idx] = true;
                ++cnt;
                if (cnt == 26) return 26; // early exit if all letters seen
            }
        }
        return cnt;
    }
};