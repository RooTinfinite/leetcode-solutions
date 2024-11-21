class Solution:
    def firstUniqChar(self, input_str: str) -> int:
        first_unique = float('inf') # first unique position/index
        
        for char_code in range(ord('a'), ord('z') + 1):
            curr_char = chr(char_code)
            
            if curr_char in input_str:
                if input_str.index(curr_char) == input_str.rindex(curr_char):
                    first_unique = min(first_unique, input_str.index(curr_char))
                    
        return first_unique if first_unique != float('inf') else -1