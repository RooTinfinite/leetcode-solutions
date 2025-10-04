class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                // No transformation needed for zero
                result[i] = nums[i];
            } else if (nums[i] > 0) {
                // Positive number: wrap around using (i + nums[i]) % nums.length
                int idx = (i + nums[i]) % nums.length;
                result[i] = nums[idx];
            } else {
                // Negative number: handle negative index wrapping
                int idx = (nums.length + (i + nums[i]) % nums.length) % nums.length;
                result[i] = nums[idx];
            }
        }
        return result;
    }
}