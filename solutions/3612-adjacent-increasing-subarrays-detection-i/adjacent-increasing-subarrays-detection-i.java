class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        for (int idx = 0; idx <= nums.size() - 2 * k; idx++) {
            if (mono(nums, idx, k) && mono(nums, idx + k, k)) {
                return true;}
        }
        return false;}

    private boolean mono(List<Integer> nums, int idx, int k) {
        for (int i = idx; i < idx + k - 1; i++) {
            if (nums.get(i) >= nums.get(i + 1)) return false; }
        return true;}
}