class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        # Check if the lengths of both strings are different; if so, they can't be rotations
        if len(s) != len(goal):
            return False

        # Concatenate 's' with itself to create a new string containing all possible rotations
        doubled_string = s + s

        # Perform KMP substring search to check if 'goal' is a substring of 'doubled_string'
        return self.kmp_search(doubled_string, goal)

    def kmp_search(self, text: str, pattern: str) -> bool:
        # Precompute the LPS (Longest Prefix Suffix) array for the pattern
        lps = self.compute_lps(pattern)
        text_index = pattern_index = 0
        text_length = len(text)
        pattern_length = len(pattern)

        # Loop through the text to find the pattern
        while text_index < text_length:
            # If characters match, move both indices forward
            if text[text_index] == pattern[pattern_index]:
                text_index += 1
                pattern_index += 1
                # If we've matched the entire pattern, return true
                if pattern_index == pattern_length:
                    return True
            # If there's a mismatch after some matches, use the LPS array to skip unnecessary comparisons
            elif pattern_index > 0:
                pattern_index = lps[pattern_index - 1]
            # If no matches, move to the next character in text
            else:
                text_index += 1
        # Pattern not found in text
        return False

    def compute_lps(self, pattern: str) -> list:
        pattern_length = len(pattern)
        lps = [0] * pattern_length
        length = 0
        index = 1

        # Build the LPS array
        while index < pattern_length:
            # If characters match, increment length and set lps value
            if pattern[index] == pattern[length]:
                length += 1
                lps[index] = length
                index += 1
            # If there's a mismatch, update length using the previous LPS value
            elif length > 0:
                length = lps[length - 1]
            # No match and length is zero
            else:
                lps[index] = 0
                index += 1

        return lps