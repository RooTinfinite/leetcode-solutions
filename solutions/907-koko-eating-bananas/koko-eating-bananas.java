class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int l = 1;
        int high = Integer.MIN_VALUE;
        for (int pile : piles) {
            high = Math.max(high, pile);
        }
        int ans = high;

        while (l <= high) {
            int mid = l + (high - l) / 2;
            if (canEatAllInTime(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    private boolean canEatAllInTime(int[] piles, int h, int k) {
        int hrs = 0;
        for (int pile : piles) {
            // Using (pile + k - 1) / k is equivalent to ceil(pile / k) and prevents overflow
            hrs += (pile + k - 1) / k;
            if (hrs > h) {
                return false;  // Early exit if we already exceed hours
            }
        }
        return hrs <= h;
    }
}