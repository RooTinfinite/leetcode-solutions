class Solution {
    public boolean rotateString(String s, String goal) {
        // Get lengths of both strings
        int n = s.length();
        int m = goal.length();
        
        // If lengths are different, rotation is impossible
        if (n != m) {
            return false;
        }
        
        // Convert to char array for manipulation
        char[] sArray = s.toCharArray();
        
        // Try all possible rotations
        for (int i = 0; i < n; i++) {
            // If current string matches goal, we found a valid rotation
            if (String.valueOf(sArray).equals(goal)) {
                return true;
            }
            
            // Perform one left rotation
            char a = sArray[0];
            for (int j = 0; j < n-1; j++) {
                sArray[j] = sArray[j+1];
            }
            sArray[n-1] = a;
        }
        
        return false;
    }
}