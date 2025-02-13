class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        # Extract all letters and reverse them
        letters = [char for char in s if char.isalpha()]
        letters.reverse()
        
        # Iterator for the reversed letters
        letter_iter = iter(letters)
        
        # Rebuild the string with letters replaced
        result = ''.join(next(letter_iter) if char.isalpha() else char for char in s)
        
        return result  