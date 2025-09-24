class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        int dp[2][26][26];  

        // Set all path to non-reachable state (-1)
        memset(dp, -1, sizeof(dp));

        // Initialize the first reachable state
        int len = words[0].size();
        int total = len;
        int head = words[0][0]-'a';
        int tail = words[0][len-1]-'a';
        dp[0][head][tail] = 0;
        
        int best = 0;        
        for (int i=1; i<n; i++) {
            len = words[i].size();
            total += len;
            head = words[i][0]-'a';
            tail = words[i][len-1]-'a';

            int curr = i & 1;
            int prev = (i + 1) & 1;

            // Clear current dp state
            memset(dp[curr], -1, sizeof(dp[curr]));

            // Check reachable head&tail combination
            for (int h=0; h<26; h++)
            for (int t=0; t<26; t++) {
                // Skip non reachable states
                if (dp[prev][h][t] == -1) continue;
                
                // Prune if no chance to beat best
                // (not enough remaining words to beat the best score)
                if (dp[prev][h][t] + (n - i) <= best) continue;

                // We can use current tail to match previous head, or vice versa
                dp[curr][head][t] = max(dp[curr][head][t], dp[prev][h][t] + (tail == h));
                dp[curr][h][tail] = max(dp[curr][h][tail], dp[prev][h][t] + (head == t));
                best = max({best, dp[curr][head][t], dp[curr][h][tail]});
            }
        }

        // Don't forget what we are here for : 
        // minimum length, not maximum reduction.
        return total - best;
    }
};