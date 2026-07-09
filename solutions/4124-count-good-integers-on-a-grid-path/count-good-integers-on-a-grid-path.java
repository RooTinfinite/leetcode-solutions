
import java.util.*;

class Solution {
    long[][][] dp = new long[17][2][10];

    public long f(String s, List<Integer> indices, int i, boolean unequal, int prev2) {
        // Base case: If we successfully placed all 16 digits, we found 1 valid number
        if (i == 16) return 1;
        
        int unqState = unequal ? 1 : 0;
        if (dp[i][unqState][prev2] != -1) return dp[i][unqState][prev2];

        int start = 0;
        boolean flag = false;
        
        // Check if the current index in the 16-digit string lies on our target path
        for (int j = 0; j < indices.size(); j++) {
            if (indices.get(j) == i) {
                start = prev2; // Next digit MUST be >= previous path digit
                flag = true;
                break;
            }
        }

        long res = 0;
        // Maximum digit we can place based on the tight bound
        int mx = unequal ? 9 : (s.charAt(i) - '0');

        for (int j = start; j <= mx; j++) {
            int nextprev2 = flag ? j : prev2;
            
            // Recurse. The boundary becomes free if we pick a digit smaller than the max
            res += f(s, indices, i + 1, unequal || (j < mx), nextprev2);
        }

        return dp[i][unqState][prev2] = res;
    }

    public long get(long r, List<Integer> indices) {
        if (r < 0) return 0; // Edge case protection
        
        // Reset the DP table for the current limit calculation
        for (int i = 0; i < 17; i++) {
            for (int j = 0; j < 2; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        // Pad the number to exactly 16 digits
        String s = String.format("%016d", r);

        // Fast-forward through leading zeros
        int index = 0;
        for (int i = 0; i < 16; i++) {
            if (s.charAt(i) != '0') {
                index = i;
                break;
            }
        }

        int prev2 = 0;
        boolean flag = false;
        
        // Check if our starting non-zero index is a cell on the path
        for (int i = 0; i < indices.size(); i++) {
            if (indices.get(i) == index) {
                flag = true;
                break;
            }
        }

        int t = s.charAt(index) - '0';
        long ans = 0;

        // Manually process the first non-zero digit
        for (int i = 0; i <= t; i++) {
            int nextprev2 = flag ? i : prev2;
            
            if (i == t) {
                ans += f(s, indices, index + 1, false, nextprev2); // Prefix matches bound
            } else {
                ans += f(s, indices, index + 1, true, nextprev2); // Prefix is smaller
            }
        }
        return ans;
    }

    public long countGoodIntegersOnPath(long l, long r, String directions) {
        List<Integer> indices = new ArrayList<>();
        int row = 0, col = 0;
        
        indices.add(0); // Top-left cell
        
        // Convert 'D' and 'R' into 1D indices
        for (char c : directions.toCharArray()) {
            if (c == 'D') row++;
            else col++;
            indices.add(4 * row + col);
        }

        return get(r, indices) - get(l - 1, indices);
    }
}