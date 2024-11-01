class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        # If input string is empty, return empty list
        if not digits:
            return []

        # Dictionary mapping digits to their corresponding letters on phone keypad
        phone_map = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }

        def backtrack(combination, next_digits):
            # Base case: if no more digits to check
            # Add the current combination to output list
            if len(next_digits) == 0:
                output.append(combination)
            else:
                # Get the first digit from remaining digits
                # For each letter corresponding to current digit
                # Recursively build combinations
                for letter in phone_map[next_digits[0]]:
                    # Add current letter to combination and process remaining digits
                    backtrack(combination + letter, next_digits[1:])

        # Initialize output list to store all combinations
        output = []
        # Start backtracking with empty combination and all digits
        backtrack("", digits)
        # Return the final list of all letter combinations
        return output