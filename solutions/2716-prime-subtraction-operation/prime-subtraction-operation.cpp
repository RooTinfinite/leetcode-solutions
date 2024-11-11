#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<int> generatePrimes(int size) {
        std::vector<bool> isPrime(size, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int currentNumber = 2; currentNumber < size; currentNumber++) {
            if (isPrime[currentNumber]) {
                for (int multiple = currentNumber * currentNumber; 
                     multiple < size; 
                     multiple += currentNumber) {
                    isPrime[multiple] = false;
                }
            }
        }
        
        std::vector<int> primeNumbers;
        for (int i = 0; i < size; i++) {
            if (isPrime[i]) {
                primeNumbers.push_back(i);
            }
        }
        return primeNumbers;
    }
    
public:
    bool primeSubOperation(std::vector<int>& numbers) {
        std::vector<int> primes = generatePrimes(1001);
        int previousValue = 0;
        
        for (int currentValue : numbers) {
            if (currentValue <= previousValue) {
                return false;
            }
            
            auto it = std::lower_bound(primes.begin(), primes.end(), 
                                     currentValue - previousValue);
            if (it != primes.begin()) {
                --it;
                currentValue -= *it;
            }
            
            previousValue = currentValue;
        }
        
        return true;
    }
};