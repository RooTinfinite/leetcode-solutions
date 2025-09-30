class Solution:
    def nonSpecialCount(self, l: int, r: int) -> int:
        # Calculate the limit up to which we need to find prime numbers
        lim = int(math.sqrt(r))
        
        # Create a list to mark primes up to lim using Sieve of Eratosthenes
        is_prime = [True] * (lim + 1)
        is_prime[0] = is_prime[1] = False # 0 and 1 are not prime numbers

        # Sieve of Eratosthenes to mark non-prime numbers
        for i in range(2, int(math.sqrt(lim)) + 1):
            if is_prime[i]:
                for j in range(i * i, lim + 1, i):
                    is_prime[j] = False

        # Count special numbers in the range [l, r]
        special_count = 0
        for i in range(2, lim + 1):
            if is_prime[i]:
                square = i * i
                if l <= square <= r:
                    special_count += 1

        # Total numbers in the range [l, r]
        total_count = r - l + 1

        # Calculate non-special numbers
        return total_count - special_count