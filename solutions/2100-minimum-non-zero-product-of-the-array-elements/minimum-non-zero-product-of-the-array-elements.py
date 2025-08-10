class Solution:
    def minNonZeroProduct(self, p: int) -> int:
        x = (1 << p) - 1
        return pow(x-1, (x-1)//2, 1_000_000_007) * x % 1_000_000_007