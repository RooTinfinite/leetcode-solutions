class Solution:
    def lastInteger(self, n: int) -> int:
        MASK = 0xAAAAAAAAAAAAAAA  # ...1010
        return ((n - 1) & MASK) + 1