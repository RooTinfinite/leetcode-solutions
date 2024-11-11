class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    int findLargestValidPrime(int num, int prev) {
        for (int i = num - prev - 1; i >= 2; i--) {
            if (isPrime(i) && num - i > prev) {
                return i;
            }
        }
        return 0;
    }
    
    bool primeSubOperation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int prev = (i == 0) ? 0 : nums[i-1];
            
            if (nums[i] <= prev) {
                return false;
            }
            
            int prime = findLargestValidPrime(nums[i], prev);
            if (prime > 0) {
                nums[i] -= prime;
            }
        }
        
        return true;
    }
};

