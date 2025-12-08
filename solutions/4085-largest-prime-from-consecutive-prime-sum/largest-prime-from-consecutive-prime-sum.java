class Solution {
    public int largestPrime(int n) {
        boolean[] isPrime = new boolean[n + 1];
        for (int i = 0; i <= n; i++) isPrime[i] = true;
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) isPrime[j] = false;
            }
        }
        
        int sum = 0, ans = 0;
        for (int i = 2; i <= n && sum <= n; i++) {
            if (isPrime[i]) {
                sum += i;
                if (sum <= n && isPrime[sum]) ans = sum;
            }
        }
        return ans;
    }
}