class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        long left = 1;
        long right = 0;
        
        // Find maximum pile as upper bound
        for (int pile : piles) {
            right = Math.max(right, pile);
        }
        
        while (left < right) {
            long mid = left + (right - left) / 2;
            
            if (canEatAll(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return (int) left;
    }
    
    private boolean canEatAll(int[] piles, int h, long k) {
        long hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k;
            if (hours > h) return false;
        }
        return true;
    }
}