class Solution {
    
    public static long splitArray(int[] nums) {
        // Maintain the sum of nums
        long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        // Maintain the left sum
        long left = nums[0];
        
        long ans = Long.MAX_VALUE;

        for (int i = 1; i < nums.length; i++) {
            // Right sum
            long right = sum-left;
            
            // Absolute difference between left sum and right sum
            long diff = Math.abs(right-left);

            // Cannot maintain strictly increasing
            if(nums[i-1]>=nums[i]){
                // Check whether the right side is strictly decreasing
                // If not, then return -1
                if(!check(nums, i + 1)) return -1;
                
                return Math.min(ans, diff);
            }
            
            // Check whether the right side is strictly decreasing
            // If is, there is a valid split, maintain the minimum answer.
            if(check(nums, i + 1))ans = Math.min(ans, diff);
            
            // Update left sum
            left+=nums[i];
        }
        
        return ans;
    }

    // Check decreasing
    static boolean check(int[] nums, int start){
        for (int i = start; i < nums.length; i++) {
            if(nums[i-1] <= nums[i])return false;
        }
        return true;
    }
}