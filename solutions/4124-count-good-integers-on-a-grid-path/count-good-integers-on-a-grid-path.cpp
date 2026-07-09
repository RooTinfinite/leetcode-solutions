long long dp[17][2][10];

class Solution {
public:
    long long f(string &s, vector<int>& indices, int i, bool unequal, int prev2) {
        // Base case: If we successfully placed all 16 digits, we found 1 valid number
        if(i == 16) return 1;
        if(dp[i][unequal][prev2] != -1) return dp[i][unequal][prev2];
        
        int start = 0;
        bool flag = false;
        int m = indices.size();
        
        // Check if the current index in the 16-digit string lies on our target path
        for(int j = 0; j < m; j++) {
            if(indices[j] == i) {
                start = prev2; // If on path, our next digit MUST be >= the previous path digit
                flag = true;
                break;
            }
        }
        
        long long res = 0;
        // Determine the maximum digit we can place based on the tight bound (unequal flag)
        int mx = unequal ? 9 : s[i] - '0';
        
        for(int j = start; j <= mx; j++) {
            // Create a temporary variable so we don't mutate the state for the next loop iteration
            int nextprev2 = prev2;
            
            // If the current cell is on the path, update the tracker to the digit we just placed
            if(flag) nextprev2 = j; 
            
            // Recurse. The boundary becomes unequal if we pick a digit smaller than the max allowed
            res += f(s, indices, i + 1, unequal | (j < mx), nextprev2);
        }
        
        return dp[i][unequal][prev2] = res;
    }
    
    long long get(long long r, vector<int>& indices) {
        if (r < 0) return 0; // Edge case protection
        memset(dp, -1, sizeof(dp));
        
        // Pad the number to exactly 16 digits as required by the 4x4 grid
        string s(16, '0');
        int n = 15;
        while(r > 0) {
            int digit = r % 10;
            s[n] = '0' + digit;
            n--;
            r /= 10;
        }
        
        // Intuition: Fast-forward through leading zeros. 
        // Leading zeros naturally satisfy the non-decreasing condition (0 <= 0 <= 0).
        int index = 0;
        for(int i = 0; i < 16; i++) {
            if(s[i] != '0') {
                index = i;
                break;
            }
        }
       
        return f(s,indices,index,0,0);
    }
    
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        vector<int> indices;
        int row = 0, col = 0;
        
        // The path always starts at the top-left cell, which is 1D index 0
        indices.push_back(0); 
        
        // Convert 'D' and 'R' directions into 1D grid indices
        for(char c : directions) {
            if(c == 'D') {
                row++;
            } else {
                col++;
            }
            indices.push_back(4 * row + col);
        }
        
        // Standard range DP calculation: [l, r] = [0, r] - [0, l - 1]
        long long ans = get(r, indices) - get(l - 1, indices);
        return ans;
    }
};