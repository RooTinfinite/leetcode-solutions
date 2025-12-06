N = 10 ** 6 + 1
primes = [1] * (N + 1)
primes[0] = primes[1] = 1 

for i in range(2, int(N ** 0.5) + 1):
    if primes[i] == 1:
        for j in range(i * i, N + 1, i):
            primes[j] = 0 

prime = set()
for i in range(2, N + 1):
    if primes[i]:
        prime.add(i)

class Solution:
    def completePrime(self, num: int) -> bool:
        num = str(num)
        for i in range(0, len(num)):
            if int(num[0 : i + 1]) not in prime:
                return False

        for i in range(len(num) - 1, -1, -1):
            if int(num[i : len(num)]) not in prime:
                return False

        return True
        