class Solution:
    def countOdds(self, low: int, high: int) -> int:
        # Initialize odd with the number of even numbers between low and high.
        odd = (high - low) // 2
        
        # If either low or high is odd, increment odd by 1.
        if low % 2 == 1 or high % 2 == 1:
            odd += 1
        
        # Return the number of odd numbers between low and high.
        return odd