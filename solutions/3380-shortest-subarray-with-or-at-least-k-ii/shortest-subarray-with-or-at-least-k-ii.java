class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        if (k == 0) {
            return 1;
        }
        int shortest = nums.length + 1;
        int[] count = new int[32];
        int val = 0;
        int start = 0;
        
        for (int i = 0; i < nums.length; ++i) {
            int num = nums[i];
            val |= num;
            for (int ibit = 0; num != 0; ++ibit) {
                count[ibit] += num & 1;
                num >>= 1;
            }
            while (val >= k && start < nums.length) {
                shortest = Math.min(shortest, i - start + 1);
                num = nums[start];
                ++start;
                for (int ibit = 0; num != 0; ++ibit) {
                    count[ibit] -= num & 1;
                    if (count[ibit] == 0) {
                        val &= ~(1 << ibit);
                    }
                    num >>= 1;
                }
            }
        }
        return shortest == (nums.length + 1) ? -1 : shortest;
    }
}