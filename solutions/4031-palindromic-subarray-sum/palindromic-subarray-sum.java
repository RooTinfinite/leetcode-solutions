class Solution {
    long M = 1_000_000_007L; 
    long p = 31L; // base prime number 

    private long pow(long x, long y) {
        // base case 
        if(y == 0) return 1L; 
        if(y == 1L) return x; 
        long half_pow = pow(x, y/ 2) % M; 
        return (((half_pow * half_pow) % M) * (y % 2 == 0 ? 1L : x)) % M; 
    }

    private void hash(int[] nums, long[] pref) {
        pref[0] = 0; 
        int n = nums.length; 

        for(int i = 0; i < n; i++) {
            pref[i + 1] = ((pref[i] * p ) % M + nums[i]) % M; 
        }
    }

    // to get Hash(l, r) 
    private long getHash(int l, int r, long[] pref, long[] power) {
        // hash(l, r) = pref[r + 1] - (pref[l] * pow(r - l + 1) ) 
        return (pref[r + 1] - (pref[l] * power[r - l + 1]) % M + M) % M;
    }

    private boolean isPalindrome(int l, int r, int n, long[] hashPref, long[] backHashPref, long[] power) {
        if (l > r) return true;
        long forward = getHash(l, r, hashPref, power);
        int revL = n - 1 - r;
        int revR = n - 1 - l;
        long backward = getHash(revL, revR, backHashPref, power);
        return forward == backward;
    }

    private void precalculatePow(int n, long[] power) {
        power[0] = 1L;

        for(int i = 0; i < n; i++) {
            power[i + 1] = (power[i] * p) % M; 
        }
    }

    public long getSum(int[] nums) {
        int n = nums.length; 
        long[] hashPref = new long[n + 1]; 
        long[] backHashPref = new long[n + 1]; 
        long[] sumPref = new long[n + 1];
        long[] powPrecalculate = new long[n + 1]; 

        // max possible sum of a subarray that is a palindrome 
        hash(nums, hashPref); 
        int[] temp = new int[n]; 
        for(int i = 0; i < n; i++) {
            temp[n - i - 1] = nums[i]; // reverse 
            sumPref[i + 1] = sumPref[i] + nums[i]; // build prefix sum 
        } 
        hash(temp, backHashPref); 

        precalculatePow(n, powPrecalculate); 

        // Normal will give me TLE as n <= 1e5 
        long ans = 0; 

        // Now we can effectively compary any two parts of the stirng if they are equal or not. 
        for(int i = 0; i < n; i++) {
            // for this index = i, say it's center of the palindrome 
            // what will be the max length of the string in any side 
            // for odd case 
            int maxOddLen = Math.min(i, n - i - 1); 
            
            int lo = 0, hi = maxOddLen; 
            int bestLength = 0; 
            while(lo <= hi) {
                int mid = (lo + hi) >> 1; 
                if(isPalindrome(i - mid, i + mid, n, hashPref, backHashPref, powPrecalculate)) {
                    // check for higher 
                    bestLength = mid; 
                    lo = mid + 1; 
                } else hi = mid - 1; 
            }
            
            int bestOddL = i - bestLength; 
            int bestOddR = i + bestLength; 
            ans = Math.max(ans, sumPref[bestOddR + 1] - sumPref[bestOddL]); 

            // for even case 
            int maxEvenLen = Math.min(i, n - i);

            lo = 0;
            hi = maxEvenLen;
            int bestEvenLength = 0;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                int l = i - mid;
                int r = i + mid - 1;

                if (isPalindrome(l, r, n, hashPref, backHashPref, powPrecalculate)) {
                    bestEvenLength = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if (bestEvenLength > 0) {
                int bestEvenL = i - bestEvenLength;
                int bestEvenR = i + bestEvenLength - 1;

                ans = Math.max(ans, sumPref[bestEvenR + 1] - sumPref[bestEvenL]);
            }
        }

        return ans; 
    }
}

// 1 2 3 4 4