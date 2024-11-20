class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        char_counts = [0] * 3
        for char in s:
            char_counts[ord(char) - ord('a')] += 1
        
        if any(count < k for count in char_counts):
            return -1
        
        string_length = len(s)
        left = 0
        max_window = 0
        
        for right in range(string_length):
            current_char = ord(s[right]) - ord('a')
            char_counts[current_char] -= 1
            
            while left <= right and any(count < k for count in char_counts):
                left_char = ord(s[left]) - ord('a')
                char_counts[left_char] += 1
                left += 1
            
            max_window = max(max_window, right - left + 1)
        
        return string_length - max_window

            