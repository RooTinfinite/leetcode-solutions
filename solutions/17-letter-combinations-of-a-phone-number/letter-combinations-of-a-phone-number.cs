public class Solution {
    // Map each digit to its corresponding letters on a phone keypad
    private Dictionary<char, string> phoneMap = new Dictionary<char, string>() {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    // List to store all generated combinations
    private List<string> output = new List<string>();
    
    // Main method that initiates the letter combination process
    public IList<string> LetterCombinations(string digits) {
        // Return empty list for empty input
        if (string.IsNullOrEmpty(digits)) {
            return new List<string>();
        }
        
        // Start the backtracking process with empty combination
        Backtrack("", digits);
        return output;
    }
    
    // Recursive backtracking method to build combinations
    private void Backtrack(string combination, string nextDigits) {
        // Base case: when no more digits to process
        // Add the current combination to results
        if (nextDigits.Length == 0) {
            output.Add(combination);
        }
        else {
            // Get the letters corresponding to the first digit
            // For each letter in the mapped string
            foreach (char letter in phoneMap[nextDigits[0]]) {
                // Add current letter to combination and process remaining digits
                // nextDigits.Substring(1) removes the first digit for next recursion
                Backtrack(combination + letter, nextDigits.Substring(1));
            }
        }
    }
}