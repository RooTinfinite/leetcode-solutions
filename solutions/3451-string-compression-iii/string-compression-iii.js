/**
 * @param {string} word
 * @return {string}
 */
var compressedString = function(word) {
    // Handle empty string case
    if (!word) return "";
    
    // Initialize result string
    let comp = "";
    
    // Initialize counter and first character
    let cnt = 1;
    let ch = word[0];
    
    // Iterate through string starting from second character
    for (let i = 1; i < word.length; i++) {
        // If current character matches previous and count < 9
        // increment counter
        if (word[i] === ch && cnt < 9) {
            cnt++;
        } 
        // If character changes or count reaches 9
        // append count and character to result
        else {
            comp += cnt.toString() + ch;
            ch = word[i];
            cnt = 1;
        }
    }
    
    // Handle the last group of characters
    comp += cnt.toString() + ch;
    
    return comp;
};