class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        # Get length of input strings (they are guaranteed to be equal length)
        n = len(s)
        
        # Create array of transformation costs between characters at each position
        # ord() converts character to ASCII value, abs() gets positive difference
        costs = [abs(ord(s[i]) - ord(t[i])) for i in range(n)]
        
        # Initialize variables for sliding window approach:
        curr_sum = 0    # Tracks current cost within window
        max_length = 0  # Stores maximum valid window length found
        left = 0        # Left pointer of sliding window
        
        # Right pointer moves through string, expanding window
        for right in range(n):
            # Add cost of new character to window sum
            curr_sum += costs[right]
            
            # If window cost exceeds maxCost, shrink window from left
            # until we're back under maxCost
            while curr_sum > maxCost and left <= right:
                curr_sum -= costs[left]
                left += 1
            
            # Current window is valid, update max_length if current window is larger
            # Window size is (right - left + 1)
            max_length = max(max_length, right - left + 1)
        
        # Return the length of longest valid substring found
        return max_length