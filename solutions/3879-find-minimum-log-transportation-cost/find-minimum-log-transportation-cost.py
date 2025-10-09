class Solution:
    def minCuttingCost(self, n: int, m: int, k: int) -> int:
        cost = 0

        if n > k:
            parts = n // k
            leftover = n - parts * k
            cost += int(k ** parts) * max(1, leftover)

        if m > k:
            parts = m // k
            leftover = m - parts * k
            cost += int(k ** parts) * max(1, leftover)

        return cost