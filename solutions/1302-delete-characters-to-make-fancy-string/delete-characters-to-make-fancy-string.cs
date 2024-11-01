public class Solution {
    public string MakeFancyString(string s) {
        // Return original string if length is less than 3
        if (s.Length < 3) {
            return s;
        }
        
        // Convert string to char array for in-place modification
        char[] chars = s.ToCharArray();
        
        // j keeps track of the position where we'll place
        // the next valid character
        int j = 2;
        
        // Iterate through string starting from index 2
        for (int i = 2; i < chars.Length; ++i) {
            // Add current character if it's different from
            // either of the two previous characters
            // This prevents three consecutive same characters
            if (chars[i] != chars[j - 1] || chars[i] != chars[j - 2]) {
                chars[j++] = chars[i];
            }
        }
        
        // Create new string with the correct length
        return new string(chars, 0, j);
    }
}