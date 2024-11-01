class Solution {
    public String makeFancyString(String s) {
        // Return original string if length is less than 3
        if (s.length() < 3) {
            return s;
        }
        
        // Convert string to char array for easier manipulation
        char[] chars = s.toCharArray();
        
        // j keeps track of the position where we'll place
        // the next valid character
        int j = 2;
        
        // Iterate through string starting from index 2
        for (int i = 2; i < chars.length; ++i) {
            // Add current character if it's different from
            // either of the two previous characters
            // This prevents three consecutive same characters
            if (chars[i] != chars[j - 1] || chars[i] != chars[j - 2]) {
                chars[j++] = chars[i];
            }
        }
        
        // Create new string with only the valid characters
        return new String(chars, 0, j);
    }
}