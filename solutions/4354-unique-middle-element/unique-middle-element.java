class Solution {
    public boolean isMiddleElementUnique(int[] nums) {
        int n = nums.length;
        int[] freq = new int[101];
        for(int ele : nums){
            freq[ele]++;
        }
        return freq[nums[n / 2]] == 1;
    }
}