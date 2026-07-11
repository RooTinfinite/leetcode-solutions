class Solution {
public:
    int reverseNum(int num) {
        int ans = 0;
        while (num != 0) {
            int rem = num % 10;
            ans = ans * 10 + rem;
            num /= 10;
        }
        return ans;
    }
    bool isPrime(int n) {

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int r = reverseNum(n);
        int sumPrimes = 0;
        for (int i = min(n, r); i <= max(n, r); i++) {
            if (i != 1 && isPrime(i))
                sumPrimes += i;
        }
        return sumPrimes;
    }
};