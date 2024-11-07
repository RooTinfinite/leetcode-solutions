class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        # Create array to store count of 1's at each bit position (32 bits for integers)
        ans = [0] * 32
        
        # Iterate through each number in candidates array
        for x in candidates:
            self.find(x, ans)
        
        # Find the maximum count of 1's across all bit positions
        return max(ans)
    
    def find(self, n: int, ans: list) -> None:
        # Start from rightmost bit (31st position)
        j = 31
        
        # Continue until all bits are processed
        while n > 0:
            # Get the rightmost bit using bitwise AND with 1
            a = n & 1
            
            # Add the bit count to corresponding position in ans array
            ans[j] += a
            
            # Right shift n by 1 to process next bit
            n >>= 1
            
            # Move to next bit position from right to left
            j -= 1