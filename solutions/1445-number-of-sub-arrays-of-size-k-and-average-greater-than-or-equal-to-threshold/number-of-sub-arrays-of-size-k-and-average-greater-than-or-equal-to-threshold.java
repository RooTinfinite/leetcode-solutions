class Solution {
        public int numOfSubarrays(int[] a, int k, int threshold) {
        int count = 0;
        for (int lo = -1, hi = 0, sumOfWin = 0, target = k * threshold; hi < a.length; ++hi) {
            sumOfWin += a[hi];
            if (hi - lo == k) { // Has the width of the window  reached k?
                if (sumOfWin >= target) {
                    ++count;
                }
                sumOfWin -= a[++lo];
            }
        }
        return count;        
    }
}