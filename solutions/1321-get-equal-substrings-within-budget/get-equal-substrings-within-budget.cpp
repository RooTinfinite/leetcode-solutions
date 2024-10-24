class Solution {
public:
    // Function to find the longest substring that can be transformed within maxCost
    static int equalSubstring(string& s, string& t, int maxCost) {
        // Length of input strings
        const int n = s.size();
        
        // Two pointers for sliding window
        int l = 0, r;
        
        // Track current cost and max length found
        int cost = 0, len = 0;

        // First pass: Try to include as many characters as possible from start
        for (r = 0; r < n; r++) {
            // Add cost of transforming current character
            cost += abs(s[r]-t[r]);
            
            // If cost exceeds maxCost, undo last addition and break
            if (cost > maxCost) {
                cost -= abs(s[r]-t[r]);
                break;
            }
        }

        // If we reached end of string and cost is acceptable,
        // entire string can be transformed
        if (r == n && cost <= maxCost) return n;
        
        // Store the length of first valid window
        len = r;

        // Second pass: Sliding window approach
        for (; r < n; r++) {
            // Add cost of including new character
            cost += abs(s[r]-t[r]);
            
            // While cost exceeds maxCost, shrink window from left
            while (cost > maxCost) {
                cost -= abs(s[l]-t[l]);
                l++;
            }
            
            // Update maximum length if current window is larger
            len = max(len, r-l+1);
        }
        
        return len;
    }
};

// Lambda function for I/O optimization
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();