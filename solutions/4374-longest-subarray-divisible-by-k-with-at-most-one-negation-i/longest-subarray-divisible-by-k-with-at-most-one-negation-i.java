class Solution {
    public int longestSubarray(int[] nums, int k) {
        int n = nums.length, best = 0;
        int[] seenAt = new int[k];
        Arrays.fill(seenAt, -1);
        for (int l = 0; l < n && n - l > best; l++) {
            long total = 0;
            for (int r = l; r < n; r++) {
                total += nums[r];
                seenAt[Math.floorMod(2 * nums[r], k)] = l;
                int s = (int) Math.floorMod(total, (long) k);
                if (s == 0 || seenAt[s] == l) best = Math.max(best, r - l + 1);
            }
        }
        return best;
    }
}