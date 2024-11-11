class PrimeNumberUtils:
    def __init__(self, max_size: int = 1001):
        self.primes = self._generate_primes(max_size)

    def _generate_primes(self, size: int) -> List[int]:
        valid = [True] * size
        valid[0] = valid[1] = False
        
        for i in range(2, size):
            if valid[i]:
                for j in range(i * i, size, i):
                    valid[j] = False
                    
        return [i for i in range(size) if valid[i]]

class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        prime_utils = PrimeNumberUtils()
        previous = 0
        
        for current in nums:
            if current <= previous:
                return False
            
            prime_index = bisect_left(prime_utils.primes, current - previous) - 1
            if prime_index != -1:
                current -= prime_utils.primes[prime_index]
                
            previous = current
            
        return True
