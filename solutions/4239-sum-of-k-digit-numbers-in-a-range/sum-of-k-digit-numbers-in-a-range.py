class Solution:
    def sumOfNumbers(self, l: int, r: int, k: int) -> int:
        MOD = 10**9 + 7
        
        count = r - l + 1
        
        # Sum of digits from l to r
        digit_sum = (count * (l + r) // 2) % MOD
        
        # count^(k-1) % MOD
        part1 = pow(count, k - 1, MOD)
        
        # (10^k - 1) / 9 under modulo
        pow10k = pow(10, k, MOD)
        inv9 = pow(9, MOD - 2, MOD)  # Fermat's little theorem
        
        geometric = ((pow10k - 1) % MOD * inv9) % MOD
        
        result = digit_sum
        result = (result * part1) % MOD
        result = (result * geometric) % MOD
        
        return result