class Solution {
    public int minDeletions(int[] nums) {
        int deletions = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                deletions++;
            }
        }
        return deletions;
    }
}