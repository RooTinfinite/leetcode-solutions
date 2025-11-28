class Solution:
    def beautifulArray(self, n: int) -> list:
        if n == 1:
            return [1]
        odd = self.beautifulArray((n + 1) // 2)
        even = self.beautifulArray(n // 2)
        return [x * 2 - 1 for x in odd] + [x * 2 for x in even]