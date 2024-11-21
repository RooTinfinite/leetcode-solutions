class Solution:
    def firstUniqChar(self, text: str) -> int:
        first_unique = float('inf') # first unique position
        
        for char_code in range(ord('a'), ord('z') + 1):
            curr_char = chr(char_code)
            
            if curr_char in text:
                if text.index(curr_char) == text.rindex(curr_char):
                    first_unique = min(first_unique, text.index(curr_char))
                    
        return first_unique if first_unique != float('inf') else -1