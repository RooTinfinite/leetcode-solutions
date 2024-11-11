import "math"

func isPrime(number int) bool {
    // Checks if a number is prime
    if number < 2 {
        return false
    }
    
    for i := 2; i <= int(math.Sqrt(float64(number))); i++ {
        if number%i == 0 {
            return false
        }
    }
    return true
}

func primeSubOperation(nums []int) bool {
    // Process each number in the array
    for i := 0; i < len(nums); i++ {
        // Calculate the upper bound for subtraction
        bound := nums[0]
        if i != 0 {
            bound = nums[i] - nums[i-1]
        }
        
        // If bound is not positive, sequence is impossible
        if bound <= 0 {
            return false
        }
        
        // Find the largest prime number less than bound
        largestPrime := 0
        for j := bound - 1; j >= 2; j-- {
            if isPrime(j) {
                largestPrime = j
                break
            }
        }
        
        // Subtract the largest prime from current number
        nums[i] -= largestPrime
    }
    
    return true
}