class Solution {
    public int countElements(int[] nums, int k) {
        int count = 0, n = nums.length;
        if (k == 0)
            return n;
        Arrays.sort(nums);
        for (int i : nums)
            if (i < nums[n - k])
                count++;
            else
                break;
        return count;
    }
}