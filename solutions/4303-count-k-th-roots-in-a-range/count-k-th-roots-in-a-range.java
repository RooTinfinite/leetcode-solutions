class Solution {

    boolean possible(long mid, int k, long n) {
        
        // handle 0 separately
        if(mid == 0)
            return true;

        long ans = 1;

        for(int i = 0; i < k; i++) {
            // avoid overflow
            if(ans > n / mid)
                return false;

            ans *= mid;
        }

        return ans <= n;
    }

    // floor(n^(1/k))
    long kthRoot(long n, int k) {

        long low = 0;
        long high = n;

        long ans = 0;

        while(low <= high) {

            long mid = low + (high - low) / 2;

            if(possible(mid, k, n)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    public int countKthRoots(int l, int r, int k) {
        long right = kthRoot(r, k);
        long left = kthRoot((long)l - 1, k);

        long ans = right - left;
        // include 0
        if(l == 0)
            ans++;

        return (int)ans;
    }
}