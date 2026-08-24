class Solution:

    # Generate all prime numbers up to n
    def getPrimes(self, n):
        isPrime = [True] * (n + 1)
        primes = []

        if n >= 0:
            isPrime[0] = False
        if n >= 1:
            isPrime[1] = False

        for i in range(2, n + 1):
            if isPrime[i]:
                primes.append(i)

                # Mark all multiples of i as composite
                if i * i <= n:
                    for j in range(i * i, n + 1, i):
                        isPrime[j] = False

        return primes

    # Return distinct prime factors of n
    def fact(self, n, primes):
        factors = []

        for p in primes:
            # No need to continue after sqrt(n)
            if p * p > n:
                break

            if n % p == 0:
                # Add the prime only once
                factors.append(p)

                # Remove all occurrences of p
                while n % p == 0:
                    n //= p

        # If something greater than 1 remains, it's prime
        if n > 1:
            factors.append(n)

        return factors

    def longestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)

        # Find the largest number
        maxi = max(nums)

        # Generate primes up to maxi
        primes = self.getPrimes(maxi)

        # Store distinct prime factors of every number
        factors = [self.fact(num, primes) for num in nums]

        # freq[p] = number of elements in the current window
        #           that contain prime p
        freq = [0] * (maxi + 1)

        distinct = 0
        left = 0
        res = 0

        # Expand the window using right
        for right in range(n):

            # Add nums[right]
            for p in factors[right]:
                if freq[p] == 0:
                    distinct += 1   # new prime introduced to the window
                freq[p] += 1

            # Shrink the window while invalid
            while distinct > k:
                for p in factors[left]:
                    freq[p] -= 1
                    if freq[p] == 0:
                        distinct -= 1   # prime completely gone from the window
                left += 1

            # Current window is valid
            res = max(res, right - left + 1)

        return res
