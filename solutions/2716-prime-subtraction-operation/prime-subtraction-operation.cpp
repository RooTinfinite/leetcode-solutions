class Solution {
public:
    // Checks if a number is prime
    bool isPrime(int number) {
        if (number < 2) return false;
        
        for (int i = 2; i <= sqrt(number); i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    bool primeSubOperation(vector<int>& nums) {
        // Process each number in the array
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the upper bound for subtraction
            int bound = (i == 0) ? nums[0] : nums[i] - nums[i - 1];
            
            // If bound is not positive, sequence is impossible
            if (bound <= 0) {
                return false;
            }
            
            // Find the largest prime number less than bound
            int largestPrime = 0;
            for (int j = bound - 1; j >= 2; j--) {
                if (isPrime(j)) {
                    largestPrime = j;
                    break;
                }
            }
            
            // Subtract the largest prime from current number
            nums[i] -= largestPrime;
        }
        
        return true;
    }
};