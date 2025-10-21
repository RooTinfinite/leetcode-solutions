class Solution {
    public int minOperations(int[] nums) {
        int cnt = 0;
        for (int x : nums) {
            if (x == nums[0]) cnt++;
        }
        return cnt < nums.length ? 1 : 0;
    }
}