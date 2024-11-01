package main

func letterCombinations(digits string) []string {
    // If input string is empty, return empty slice
    if len(digits) == 0 {
        return []string{}
    }

    // Map digits to their corresponding letters on phone keypad
    phoneMap := map[byte]string{
        '2': "abc",
        '3': "def",
        '4': "ghi",
        '5': "jkl",
        '6': "mno",
        '7': "pqrs",
        '8': "tuv",
        '9': "wxyz",
    }

    output := []string{}

    var backtrack func(combination string, nextDigits string)
    backtrack = func(combination string, nextDigits string) {
        // Base case: if no more digits to check
        if len(nextDigits) == 0 {
            output = append(output, combination)
            return
        }

        // Get the current digit and its corresponding letters
        currentDigit := nextDigits[0]
        letters := phoneMap[currentDigit]

        // For each letter corresponding to current digit
        for i := 0; i < len(letters); i++ {
            // Add current letter to combination and process remaining digits
            backtrack(combination+string(letters[i]), nextDigits[1:])
        }
    }

    // Start backtracking with empty combination and all digits
    backtrack("", digits)
    return output
}