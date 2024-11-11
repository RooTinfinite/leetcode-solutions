# Generate prime numbers using Sieve of Eratosthenes
is_prime = [True] * 1001
is_prime[0] = is_prime[1] = False

for current_number in range(2, len(is_prime)):
    if is_prime[current_number]:
        for multiple in range(current_number * current_number, len(is_prime), current_number):
            is_prime[multiple] = False

prime_numbers = [number for number in range(len(is_prime)) if is_prime[number]]

class Solution:
    def primeSubOperation(self, numbers: List[int]) -> bool:
        previous_value = 0
        
        for current_value in numbers:
            if current_value <= previous_value:
                return False
            
            prime_index = bisect_left(prime_numbers, current_value - previous_value) - 1
            
            if prime_index != -1:
                current_value -= prime_numbers[prime_index]
                
            previous_value = current_value
            
        return True