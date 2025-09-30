class Solution {
public:
    int nonSpecialCount(int l, int r) {
        // Calculate the limit up to which we need to find prime numbers
        int lim = (int)(sqrt(r));

        // Create a boolean array to mark primes up to lim using Sieve of Eratosthenes
        vector<bool> v(lim + 1, true);
        v[0] = v[1] = false; // 0 and 1 are not prime numbers

        // Sieve of Eratosthenes to mark non-prime numbers
        for (int i = 2; i * i <= lim; i++) {
            if (v[i]) {
                for (int j = i * i; j <= lim; j += i) {
                    v[j] = false;
                }
            }
        }

        // Count special numbers in the range [l, r]
        int cnt = 0;
        for (int i = 2; i <= lim; i++) {
            if (v[i]) {
                int square = i * i;
                if (square >= l && square <= r) {
                    cnt++;
                }
            }
        }

        // Total numbers in the range [l, r]
        int totalCount = r - l + 1;

        // Calculate non-special numbers
        return totalCount - cnt;
    }
};