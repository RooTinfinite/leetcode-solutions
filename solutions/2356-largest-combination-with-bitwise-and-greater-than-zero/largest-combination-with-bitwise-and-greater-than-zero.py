class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        max_count = 0
        
        # Check each bit position from 0 to 31
        for bit in range(32):
            current_count = 0
            # Count numbers that have 1 at current bit position
            for num in candidates:
                if num & (1 << bit):
                    current_count += 1
            max_count = max(max_count, current_count)
            
        return max_count