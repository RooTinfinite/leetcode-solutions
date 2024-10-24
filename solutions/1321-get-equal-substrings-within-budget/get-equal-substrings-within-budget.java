class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        // Length of input strings
        final int n = s.length();
        
        // Two pointers for sliding window
        int l = 0, r;
        
        // Track current cost and max length found
        int cost = 0, len = 0;
        
        // First pass: Try to include as many characters as possible from start
        for (r = 0; r < n; r++) {
            // Add cost of transforming current character
            cost += Math.abs(s.charAt(r) - t.charAt(r));
            
            // If cost exceeds maxCost, undo last addition and break
            if (cost > maxCost) {
                cost -= Math.abs(s.charAt(r) - t.charAt(r));
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
            cost += Math.abs(s.charAt(r) - t.charAt(r));
            
            // While cost exceeds maxCost, shrink window from left
            while (cost > maxCost) {
                cost -= Math.abs(s.charAt(l) - t.charAt(l));
                l++;
            }
            
            // Update maximum length if current window is larger
            len = Math.max(len, r - l + 1);
        }
        
        return len;
    }
}