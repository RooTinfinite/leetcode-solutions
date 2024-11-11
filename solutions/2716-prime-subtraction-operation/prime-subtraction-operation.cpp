class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = getMaxElement(nums);
        
        // Sieve of Atkin
        vector<bool> sieve(maxElement + 1, false);
        if (maxElement > 2) sieve[2] = true;
        if (maxElement > 3) sieve[3] = true;
        
        for (int x = 1; x * x <= maxElement; x++) {
            for (int y = 1; y * y <= maxElement; y++) {
                int n = (4 * x * x) + (y * y);
                if (n <= maxElement && (n % 12 == 1 || n % 12 == 5)) {
                    sieve[n] = !sieve[n];
                }
                
                n = (3 * x * x) + (y * y);
                if (n <= maxElement && n % 12 == 7) {
                    sieve[n] = !sieve[n];
                }
                
                n = (3 * x * x) - (y * y);
                if (x > y && n <= maxElement && n % 12 == 11) {
                    sieve[n] = !sieve[n];
                }
            }
        }
        
        for (int i = 5; i * i <= maxElement; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= maxElement; j += i * i) {
                    sieve[j] = false;
                }
            }
        }
        
        int currValue = 1;
        int i = 0;
        while (i < nums.size()) {
            int difference = nums[i] - currValue;
            
            if (difference < 0) {
                return false;
            }
            
            if (sieve[difference] == true || difference == 0) {
                i++;
                currValue++;
            } else {
                currValue++;
            }
        }
        return true;
    }
    
private:
    int getMaxElement(vector<int>& nums) {
        int max = -1;
        for (int num : nums) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }
};