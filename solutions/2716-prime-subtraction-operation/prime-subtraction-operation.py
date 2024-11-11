# Create a boolean array of size 1001 initialized with True
# This will be used to mark prime numbers using Sieve of Eratosthenes algorithm
is_prime = [True] * 1001

# 0 and 1 are not prime numbers
is_prime[0] = is_prime[1] = False

# Implement Sieve of Eratosthenes algorithm
for current_number in range(2, len(is_prime)):
    # If current_number is prime
    if is_prime[current_number]:
        # Mark all its multiples as non-prime
        # Start from current_number^2 as smaller multiples would have been marked already
        for multiple in range(current_number * current_number, len(is_prime), current_number):
            is_prime[multiple] = False

# Create a list of all prime numbers using list comprehension
prime_numbers = [number for number in range(len(is_prime)) if is_prime[number]]

class Solution:
    def primeSubOperation(self, numbers: List[int]) -> bool:
        # Keep track of previous value to ensure strictly increasing sequence
        previous_value = 0
        
        for current_value in numbers:
            # If current value is less than or equal to previous, sequence cannot be strictly increasing
            if current_value <= previous_value:
                return False
            
            # Find largest prime number that can be subtracted while keeping sequence strictly increasing
            # Using binary search to find insertion point and getting previous prime
            prime_index = bisect_left(prime_numbers, current_value - previous_value) - 1
            
            # If valid prime found, subtract it from current value
            if prime_index != -1:
                current_value -= prime_numbers[prime_index]
            
            # Update previous value for next iteration
            previous_value = current_value
            
        return True
                
