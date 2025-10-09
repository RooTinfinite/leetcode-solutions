class Solution {
public:
    bool is_prime(long long num) {
        if (num <= 1) {
            return false;
        }
        if (num <= 3) {
            return true;
        }
        if (num % 2 == 0 || num % 3 == 0) {
            return false;
        }

        for (long long i = 5; i * i <= num; i = i + 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        set<long long> primes_found;
        int n = s.length();

        if (n == 0) {
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            long long current_num = s[i] - '0';

            if (is_prime(current_num)) {
                primes_found.insert(current_num);
            }

            for (int j = i + 1; j < n; ++j) {
                int digit = s[j] - '0';

                if (current_num > LLONG_MAX / 10 || (current_num == LLONG_MAX / 10 && digit > LLONG_MAX % 10)) {
                    break;
                }
                
                current_num = current_num * 10 + digit;
                if (is_prime(current_num)) {
                    primes_found.insert(current_num);
                }
            }
        }

        if (primes_found.empty()) {
            return 0;
        }

        vector<long long> sorted_primes(primes_found.begin(), primes_found.end());
        
        sort(sorted_primes.rbegin(), sorted_primes.rend());

        long long sum_of_top_primes = 0;
        int count = 0;
        for (long long p : sorted_primes) {
            if (count < 3) {
                sum_of_top_primes += p;
                count++;
            } else {
                break;
            }
        }

        return sum_of_top_primes;
    }
};