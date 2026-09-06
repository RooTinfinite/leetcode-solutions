class Solution {
    public int countGoodRotations(int[] nums) {
        long sum = 0; 
        for(int x: nums) sum += x; 
        long pre = 0, cnt = 0; 
        for(int i = 0; i < nums.length; i++) {
            if(i >= nums.length / 2) {
                // Now we have half check if greater than rest half 
                if(pre != sum - pre) cnt++; 
                // remove the last one 
                pre -= nums[i - nums.length / 2]; 
            }
            pre += nums[i]; // rotate 
        }
        return (int)cnt; 
    }
}