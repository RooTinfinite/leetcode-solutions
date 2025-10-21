class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for (char c : s) {
            // distance (c → 'a') going forward in the circular alphabet
            int dist = (26 - (c - 'a')) % 26;
            ans = max(ans, dist);
        }
        return ans;
    }
};
