class Solution:
    def reverseNum(self, num):
        ans = 0
        while num != 0:
            rem = num % 10
            ans = ans * 10 + rem
            num //= 10
        return ans

    def isPrime(self, n):
        if n < 2:
            return False
        i = 2
        while i * i <= n:
            if n % i == 0:
                return False
            i += 1
        return True

    def sumOfPrimesInRange(self, n):
        r = self.reverseNum(n)
        sumPrimes = 0
        for i in range(min(n, r), max(n, r) + 1):
            if i != 1 and self.isPrime(i):
                sumPrimes += i
        return sumPrimes