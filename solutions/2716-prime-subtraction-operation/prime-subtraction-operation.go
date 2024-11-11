func primeSubOperation(nums []int) bool {
    maxElement := getMaxElement(nums)
    
    // Create Sieve of Eratosthenes array to identify prime numbers
    sieve := make([]bool, maxElement+1)
    fill(sieve, true)
    sieve[1] = false
    
    for i := 2; i <= int(math.Sqrt(float64(maxElement+1))); i++ {
        if sieve[i] {
            for j := i * i; j <= maxElement; j += i {
                sieve[j] = false
            }
        }
    }
    
    // Check if array can be made strictly increasing by subtracting prime numbers
    currValue := 1
    i := 0
    for i < len(nums) {
        difference := nums[i] - currValue
        
        // Return false if current number is already smaller than required value
        if difference < 0 {
            return false
        }
        
        // Move to next number if difference is prime or zero
        if sieve[difference] == true || difference == 0 {
            i++
            currValue++
        } else {
            currValue++
        }
    }
    return true
}

// Helper function to find maximum element in array
func getMaxElement(nums []int) int {
    max := -1
    for _, num := range nums {
        if num > max {
            max = num
        }
    }
    return max
}

// Helper function to initialize boolean array
func fill(arr []bool, value bool) {
    for i := range arr {
        arr[i] = value
    }
}
