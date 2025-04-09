class Solution {
    public int minOperations(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int c = 0,a = 0;
        if(nums[0] < k){
            return -1;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i] == k){
                continue;
            }
            if(nums[i] != a){
                c++;
            }
            a = nums[i];
        }
        return c;
    }
}