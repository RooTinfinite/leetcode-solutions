class Solution {

    // Generate all prime numbers up to n
    private int[] getPrimes(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        List<Integer> primeList = new ArrayList<>();

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primeList.add(i);

                // Mark all multiples of i as composite
                if ((long) i * i <= n) {
                    for (int j = i * i; j <= n; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
        }

        int[] primes = new int[primeList.size()];
        for (int i = 0; i < primes.length; i++) {
            primes[i] = primeList.get(i);
        }
        return primes;
    }

    // Return distinct prime factors of n
    private List<Integer> fact(int n, int[] primes) {
        List<Integer> factors = new ArrayList<>();

        for (int p : primes) {
            // No need to continue after sqrt(n)
            if ((long) p * p > n)
                break;

            if (n % p == 0) {
                // Add the prime only once
                factors.add(p);

                // Remove all occurrences of p
                while (n % p == 0) {
                    n /= p;
                }
            }
        }

        // If something greater than 1 remains, it's prime
        if (n > 1) {
            factors.add(n);
        }

        return factors;
    }

    public int longestSubarray(int[] nums, int k) {
        int n = nums.length;

        // Find the largest number
        int maxi = Arrays.stream(nums).max().getAsInt();

        // Generate primes up to maxi
        int[] primes = getPrimes(maxi);

        // Store distinct prime factors of every number
        List<List<Integer>> factors = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            factors.add(fact(nums[i], primes));
        }

        // freq[p] = number of elements in the current window
        //           that contain prime p
        int[] freq = new int[maxi + 1];

        int distinct = 0;
        int left = 0;
        int res = 0;

        // Expand the window using right
        for (int right = 0; right < n; right++) {

            // Add nums[right]
            for (int p : factors.get(right)) {
                if (freq[p] == 0) {
                    distinct++;   // new prime introduced to the window
                }
                freq[p]++;
            }

            // Shrink the window while invalid
            while (distinct > k) {
                for (int p : factors.get(left)) {
                    freq[p]--;
                    if (freq[p] == 0) {
                        distinct--;   // prime completely gone from the window
                    }
                }
                left++;
            }

            // Current window is valid
            res = Math.max(res, right - left + 1);
        }

        return res;
    }
}