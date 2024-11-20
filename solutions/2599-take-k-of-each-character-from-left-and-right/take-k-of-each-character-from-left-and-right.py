class Solution:
    def takeCharacters(self, text: str, req: int) -> int:
        freq = [0] * 3
        size = len(text)
        
        for char in text:
            freq[ord(char) - ord('a')] += 1
        
        left = 0
        right = 0
        
        if freq[0] < req or freq[1] < req or freq[2] < req:
            return -1
        
        for right in range(size):
            freq[ord(text[right]) - ord('a')] -= 1
            
            if freq[0] < req or freq[1] < req or freq[2] < req:
                freq[ord(text[left]) - ord('a')] += 1
                left += 1
        
        return size - (right - left + 1)

        