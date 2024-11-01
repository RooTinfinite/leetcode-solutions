class Solution:
    def makeFancyString(self, s: str) -> str:
        # Return original string if length is less than 3
        if len(s) < 3:
            return s
        
        # Convert string to list for easier manipulation
        chars = list(s)
        j = 2
        
        # Iterate through string starting from index 2
        for i in range(2, len(s)):
            # Add current character if it's different from
            # either of the two previous characters
            if chars[i] != chars[j-1] or chars[i] != chars[j-2]:
                chars[j] = chars[i]
                j += 1
        
        # Join the characters up to index j to form the fancy string
        return ''.join(chars[:j])