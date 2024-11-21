class Solution:
    def firstUniqChar(self, text: str) -> int:
        first_pos = float('inf')
        
        for char_code in range(ord('a'), ord('z') + 1):
            curr_char = chr(char_code)
            
            if curr_char in text:
                if text.index(curr_char) == text.rindex(curr_char):
                    first_pos = min(first_pos, text.index(curr_char))
                    
        return first_pos if first_pos != float('inf') else -1