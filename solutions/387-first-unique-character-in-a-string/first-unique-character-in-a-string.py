class Solution:
    def firstUniqChar(self, text: str) -> int:
        first_unique_position = float('inf')
        
        for letter in range(ord('a'), ord('z') + 1):
            current_char = chr(letter)
            
            if current_char in text:
                first_occurrence = text.index(current_char)
                last_occurrence = text.rindex(current_char)
                
                if first_occurrence == last_occurrence:
                    first_unique_position = min(first_unique_position, first_occurrence)
        
        return first_unique_position if first_unique_position != float('inf') else -1