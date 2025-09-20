class Solution:
    def makeIntegerBeautiful(self, n: int, target: int) -> int:
        def digits(n: int):
            while n > 0:
                yield n % 10
                n //= 10

        multiplier = 1
        min_add = 0
        while sum(digits(n + min_add)) > target:
            multiplier *= 10
            min_add = multiplier - n % multiplier
        
        return min_add