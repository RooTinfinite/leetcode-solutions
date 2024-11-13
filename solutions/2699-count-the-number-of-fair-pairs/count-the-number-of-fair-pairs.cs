public class Solution {
    private int BinSearch(int[] nums, int l, int r, int target) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) r = m - 1;
            else l = m + 1;
        }
        return r;
    }
    
    public long CountFairPairs(int[] nums, int lower, int upper) {
        Array.Sort(nums);
        long res = 0;
        for (int i = 0; i < nums.Length; i++) {
            int low = lower - nums[i];
            int up = upper - nums[i];
            res += BinSearch(nums, i + 1, nums.Length - 1, up + 1) - 
                   BinSearch(nums, i + 1, nums.Length - 1, low);
        }
        return res;
    }
}
