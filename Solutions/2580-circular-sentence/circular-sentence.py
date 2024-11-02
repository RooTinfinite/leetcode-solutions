class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        # Get the length of the sentence
        n = len(sentence)
        
        # First check: Compare first and last character of sentence
        # For a circular sentence, they must match
        if sentence[0] != sentence[n-1]:
            return False
            
        # Iterate through the sentence, starting from index 1 to n-2
        # We don't need to check first and last characters again
        for i in range(1, n-1):
            # When we find a space character
            if sentence[i] == ' ':
                # Check if the character before space (last char of current word)
                # matches the character after space (first char of next word)
                if sentence[i-1] != sentence[i+1]:
                    return False
                    
        # If we made it through all checks, the sentence is circular
        return True