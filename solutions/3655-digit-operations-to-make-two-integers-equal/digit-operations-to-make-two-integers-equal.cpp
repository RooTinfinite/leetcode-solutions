class Solution {
public:
    int minOperations(int n, int m) {
        const int dig_count = count_digits(n);
        const int max_number = pow(10, dig_count);

        std::vector<bool> primes(max_number + 1, true);
        get_primes(primes, max_number);
        primes[1] = false;

        if (primes[n]) return -1;

        std::unordered_map<int, int> min_sum;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater< std::pair<int, int> >  > pq;

        min_sum[n] = n;
        pq.push(std::make_pair(n, n));
        int pow_10, new_num, new_sum;

        // Modified Dijkstra
        while ( pq.empty() == false ) {
            auto[sum, num1] = pq.top();
            pq.pop();

            if (num1 == m) return sum;

            pow_10 = 1;
            for (int i = 1, num2 = num1; i <= dig_count && num2; i++) {
                if (num2 % 10 < 9) {
                    new_num = num1 + pow_10;
                    new_sum = sum + new_num;
                    if (primes[new_num] == false && ( min_sum.find(new_num) == min_sum.end() || min_sum[new_num] > new_sum )) {
                        min_sum[new_num] = new_sum;
                        pq.push(std::make_pair(new_sum, new_num));
                    }
                }
                if (num2 % 10 > 0) {
                    new_num = num1 - pow_10;
                    new_sum = sum + new_num;
                    if (primes[new_num] == false && ( min_sum.find(new_num) == min_sum.end() || min_sum[new_num] > new_sum )) {
                        min_sum[new_num] = new_sum;
                        pq.push(std::make_pair(new_sum, new_num));
                    }
                }
                num2 /= 10;
                pow_10 *= 10;
            }
        }

        return -1;
    }

private:
    // Count the digits of the number
    int count_digits(int n) {
        int count = 0;
        while (n) {
            ++count;
            n /= 10;
        }

        return count;
    }

    // Get all prime numbers from 2 to N
    // Sieve of Eratosthenes approach!
    void get_primes(std::vector<bool>& prime, const int N) {
        for (int i = 2; i <= sqrt(N); i++) {
            if (prime[i]) {
                for (int j = i * i; j <= N; j += i) prime[j] = false;
            }
        }
    }
};