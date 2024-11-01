/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    // If input string is empty, return empty array
    if (!digits) {
        return [];
    }

    // Dictionary mapping digits to their corresponding letters on phone keypad
    const phoneMap = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    };

    const output = [];

    function backtrack(combination, nextDigits) {
        // Base case: if no more digits to check
        // Add the current combination to output array
        if (nextDigits.length === 0) {
            output.push(combination);
        } else {
            // Get the first digit from remaining digits
            // For each letter corresponding to current digit
            // Recursively build combinations
            for (let letter of phoneMap[nextDigits[0]]) {
                // Add current letter to combination and process remaining digits
                backtrack(combination + letter, nextDigits.slice(1));
            }
        }
    }

    // Start backtracking with empty combination and all digits
    backtrack("", digits);
    
    // Return the final array of all letter combinations
    return output;
};