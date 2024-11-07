class Solution:
    def largestCombination(self, candidates):
        max_count = 0  # Variable to track the maximum count of set bits.
        for i in range(24):
            count = 0  # Count of numbers with the i-th bit set.
            for num in candidates:
                if (num & (1 << i)) != 0:  # Check if the i-th bit is set.
                    count += 1
            max_count = max(max_count, count)  # Update the maximum count.
        return max_count