class Solution:
    def compressedString(self, word: str) -> str:
        # Handle empty string case
        if not word:
            return ""
        
        # Initialize result string
        comp = []
        
        # Initialize counter and first character
        cnt = 1
        ch = word[0]
        
        # Iterate through string starting from second character
        for i in range(1, len(word)):
            # If current character matches previous and count < 9
            # increment counter
            if word[i] == ch and cnt < 9:
                cnt += 1
            # If character changes or count reaches 9
            # append count and character to result
            else:
                comp.append(str(cnt))    # Convert count to string and append
                comp.append(ch)          # Append the character
                ch = word[i]            # Update current character
                cnt = 1                 # Reset counter for new character
        
        # Handle the last group of characters
        comp.append(str(cnt))    # Append final count
        comp.append(ch)          # Append final character
        
        return "".join(comp)