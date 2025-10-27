class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int diff = Integer.MAX_VALUE;
        int sz = nums.length;
        Arrays.sort(nums);
        for (int i = 0; i < sz && diff != 0; ++i) {
            for (int j = i + 1; j < sz - 1; ++j) {
                int complement = target - nums[i] - nums[j];
                var idx = Arrays.binarySearch(nums, j + 1, sz - 1, complement);
                int hi = idx >= 0 ? idx : ~idx, lo = hi - 1;
                if (
                    hi < sz && Math.abs(complement - nums[hi]) < Math.abs(diff)
                ) diff = complement - nums[hi];
                if (
                    lo > j && Math.abs(complement - nums[lo]) < Math.abs(diff)
                ) diff = complement - nums[lo];
            }
        }
        return target - diff;
    }
}