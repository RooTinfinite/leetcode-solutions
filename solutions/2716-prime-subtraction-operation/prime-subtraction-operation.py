import math

class Solution:
    def isPrime(self, number: int) -> bool:
        if number < 2:
            return False
        
        for i in range(2, int(math.sqrt(number)) + 1):
            if number % i == 0:
                return False
        return True
    
    def primeSubOperation(self, nums: List[int]) -> bool:
        for i in range(len(nums)):
            bound = nums[0] if i == 0 else nums[i] - nums[i-1]
            
            if bound <= 0:
                return False
            
            largest_prime = 0
            for j in range(bound - 1, 1, -1):
                if self.isPrime(j):
                    largest_prime = j
                    break
            
            nums[i] -= largest_prime
        
        return True