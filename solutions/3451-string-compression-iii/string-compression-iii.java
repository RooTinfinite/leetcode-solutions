class Solution {
    public String compressedString(String word) {
        // Handle empty string case
        if (word.isEmpty()) {
            return "";
        }
        
        // Initialize result StringBuilder
        StringBuilder comp = new StringBuilder();
        
        // Initialize counter and first character
        int cnt = 1;
        char ch = word.charAt(0);
        
        // Iterate through string starting from second character
        for (int i = 1; i < word.length(); i++) {
            // If current character matches previous and count < 9
            // increment counter
            if (word.charAt(i) == ch && cnt < 9) {
                cnt++;
            }
            // If character changes or count reaches 9
            // append count and character to result
            else {
                comp.append(cnt);    // Convert count to string and append
                comp.append(ch);     // Append the character
                ch = word.charAt(i); // Update current character
                cnt = 1;            // Reset counter for new character
            }
        }
        
        // Handle the last group of characters
        comp.append(cnt);    // Append final count
        comp.append(ch);     // Append final character
        
        return comp.toString();
    }
}