class Solution {

    public boolean rotateString(String s, String goal) {
        // Check if the lengths of both strings are different; if so, they can't be rotations
        if (s.length() != goal.length()) return false;

        // Concatenate 's' with itself to create a new string containing all possible rotations
        String doubledString = s + s;

        // Perform KMP substring search to check if 'goal' is a substring of 'doubledString'
        return kmpSearch(doubledString, goal);
    }

    private boolean kmpSearch(String text, String pattern) {
        // Precompute the LPS (Longest Prefix Suffix) array for the pattern
        int[] lps = computeLPS(pattern);
        int textIndex = 0, patternIndex = 0;
        int textLength = text.length(), patternLength = pattern.length();

        // Loop through the text to find the pattern
        while (textIndex < textLength) {
            // If characters match, move both indices forward
            if (text.charAt(textIndex) == pattern.charAt(patternIndex)) {
                textIndex++;
                patternIndex++;
                // If we've matched the entire pattern, return true
                if (patternIndex == patternLength) return true;
            }
            // If there's a mismatch after some matches, use the LPS array to skip unnecessary comparisons
            else if (patternIndex > 0) {
                patternIndex = lps[patternIndex - 1];
            }
            // If no matches, move to the next character in text
            else {
                textIndex++;
            }
        }
        // Pattern not found in text
        return false;
    }

    private int[] computeLPS(String pattern) {
        int patternLength = pattern.length();
        int[] lps = new int[patternLength];
        int length = 0, index = 1;

        // Build the LPS array
        while (index < patternLength) {
            // If characters match, increment length and set lps value
            if (pattern.charAt(index) == pattern.charAt(length)) {
                length++;
                lps[index++] = length;
            }
            // If there's a mismatch, update length using the previous LPS value
            else if (length > 0) {
                length = lps[length - 1];
            }
            // No match and length is zero
            else {
                lps[index++] = 0;
            }
        }
        return lps;
    }
}