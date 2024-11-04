/**
 * Compresses a string by counting consecutive characters (max 9)
 * Example: "aaa" -> "3a", "aabbcc" -> "2a2b2c"
 * @param {string} word
 * @return {string}
 */
var compressedString = function(word) {
    // Initialize empty result string
    let comp = "";
    
    // Get total length of input string
    let n = word.length;
    
    // Iterate through string with variable increment
    for(let i = 0; i < n; ) {
        // Get current character to count
        let char = word[i];
        
        // Set maximum look-ahead limit to i + 9 
        // This ensures we never count more than 9 consecutive chars
        let k = i + 9;
        
        // Initialize counter for current character sequence
        let length = 0;
        
        // Count consecutive occurrences of current char
        // Stop if: reached end of string OR hit max count of 9 OR different char found
        while(i < n && i < k && word[i] == char) {
            length += 1;
            i += 1;
        }
        
        // Add the count and character to result string
        comp += String(length) + char;
    }
    
    return comp;
};