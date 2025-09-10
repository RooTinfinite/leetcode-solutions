class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        count = 0
        n = num
        while n >= 10**(k-1):
            d = n % 10**k
            n = n // 10
            if d != 0 and num % d == 0:
                count += 1
        return count