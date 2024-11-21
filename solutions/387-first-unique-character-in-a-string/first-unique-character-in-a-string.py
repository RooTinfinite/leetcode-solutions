class Solution:
    def firstUniqChar(self, input_str: str) -> int:
        first_unique = []
        
        for letter in 'abcdefghijklmnopqrstuvwxyz':
            if input_str.count(letter) == 1:
                first_unique.append(input_str.find(letter))
        
        return min(first_unique) if first_unique else -1