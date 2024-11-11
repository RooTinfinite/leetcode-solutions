class Solution {
    func primeSubOperation(_ nums: [Int]) -> Bool {
        var numbers = nums
        
        // Generate primes up to 1000
        var sieve = Array(repeating: true, count: 1001)
        sieve[0] = false
        sieve[1] = false
        
        for i in 2...Int(sqrt(Double(1000))) {
            if sieve[i] {
                var j = i * i
                while j <= 1000 {
                    sieve[j] = false
                    j += i
                }
            }
        }
        
        // Process from left to right
        for i in 0..<numbers.count {
            let target = i == 0 ? 0 : numbers[i-1]
            if numbers[i] <= target {
                return false
            }
            
            // Find largest prime to subtract while keeping array strictly increasing
            for p in (1...numbers[i]).reversed() where sieve[p] {
                let newVal = numbers[i] - p
                if newVal > target {
                    numbers[i] = newVal
                    break
                }
            }
        }
        
        return true
    }
}