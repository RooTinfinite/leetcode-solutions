class Solution {
    func letterCombinations(_ digits: String) -> [String] {
        // If input string is empty, return empty array
        if digits.isEmpty {
            return []
        }
        
        // Dictionary mapping digits to their corresponding letters on phone keypad
        let phoneMap: [Character: String] = [
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        ]
        
        var output: [String] = []
        
        func backtrack(_ combination: String, _ nextDigits: String) {
            // Base case: if no more digits to check
            // Add the current combination to output array
            if nextDigits.isEmpty {
                output.append(combination)
            } else {
                // Get the first digit from remaining digits
                let digit = nextDigits.first!
                // Get the letters corresponding to current digit
                let letters = phoneMap[digit]!
                
                // For each letter corresponding to current digit
                // Recursively build combinations
                for letter in letters {
                    // Add current letter to combination and process remaining digits
                    let remainingDigits = String(nextDigits.dropFirst())
                    backtrack(combination + String(letter), remainingDigits)
                }
            }
        }
        
        // Start backtracking with empty combination and all digits
        backtrack("", digits)
        // Return the final array of all letter combinations
        return output
    }
}