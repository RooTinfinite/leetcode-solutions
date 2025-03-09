class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        # Extend the array to handle circular sequences
        for i in range(k - 1):
            colors.append(colors[i])

        length = len(colors)
        result = 0
        # Initialize the bounds of the sliding window
        left = 0
        right = 1

        while right < length:
            # Check if the current color is the same as the last one
            if colors[right] == colors[right - 1]:

                # Pattern breaks, reset window from the current position
                left = right
                right += 1
                continue

            # Extend window
            right += 1

            # Skip counting sequence if its length is less than k
            if right - left < k:
                continue

            # Record a valid sequence and shrink window from the left to search for more
            result += 1
            left += 1

        return result