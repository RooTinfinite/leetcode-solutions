/**
 * @param {string} sentence
 * @return {boolean}
 */
var isCircularSentence = function(sentence) {
    // Get the length of the sentence
    const n = sentence.length;
    
    // First check: Compare first and last character of sentence
    if (sentence[0] !== sentence[n-1]) return false;
    
    // Iterate through the sentence, starting from index 1 to n-2
    for (let i = 1; i < n-1; i++) {
        // When we find a space character
        if (sentence[i] === ' ') {
            // Check if the character before space matches the character after space
            if (sentence[i-1] !== sentence[i+1]) return false;
        }
    }
    
    // If we made it through all checks, the sentence is circular
    return true;
};