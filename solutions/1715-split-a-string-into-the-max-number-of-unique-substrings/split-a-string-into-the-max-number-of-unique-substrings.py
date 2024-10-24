class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        seen = set()  # Set to store unique substrings
        max_count = [0]  # List to store the maximum count of unique substrings (using list for mutable reference)
        
        # Call the backtracking function to find the maximum count
        self.backtrack(s, 0, seen, 0, max_count)
        
        return max_count[0]  # Return the final result

    def backtrack(self, s: str, start: int, seen: set, count: int, max_count: list) -> None:
        # Pruning: If the remaining characters plus current count can't exceed max_count, return
        if count + (len(s) - start) <= max_count[0]:
            return

        # Base case: If we've reached the end of the string
        if start == len(s):
            max_count[0] = max(max_count[0], count)  # Update max_count if necessary
            return

        # Try all possible substrings starting from 'start'
        for end in range(start + 1, len(s) + 1):
            substring = s[start:end]  # Extract substring
            
            # If the substring is not in the set (i.e., it's unique)
            if substring not in seen:
                seen.add(substring)  # Add the substring to the set
                
                # Recursively call backtrack with updated parameters
                self.backtrack(s, end, seen, count + 1, max_count)
                
                seen.remove(substring)  # Remove the substring from the set (backtracking)