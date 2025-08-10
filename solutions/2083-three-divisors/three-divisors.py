class Solution:
    def isThree(self, n: int) -> bool:
        return sum(2 if i != n // i else 1 for i in range(1, int(n ** 0.5) + 1) if n % i == 0) == 3