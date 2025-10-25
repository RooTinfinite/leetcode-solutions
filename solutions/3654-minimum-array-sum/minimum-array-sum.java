class Solution {
    public int minArraySum(int[] nums, int k, int op1, int op2) {
        int[][][] dp = new int[nums.length + 1][op1 + 1][op2 + 1];
        
        // Initialize dp with a large value, meaning unvisited states
        for (int i = 0; i <= nums.length; i++) {
            for (int j = 0; j <= op1; j++) {
                for (int l = 0; l <= op2; l++) {
                    dp[i][j][l] = Integer.MAX_VALUE;
                }
            }
        }

        int result = recur(op1, op2, nums, 0, k, dp);
        
        // Return result if valid; otherwise, return 0 if no valid result is found
        return result == Integer.MAX_VALUE ? 0 : result;
    }

    public int recur(int opt1, int opt2, int[] nums, int idx, int k, int[][][] dp) {
        
        if (idx == nums.length) {
            return 0;
        }

        // If the result is already computed for this state, return it
        if (dp[idx][opt1][opt2] != Integer.MAX_VALUE) {
            return dp[idx][opt1][opt2];
        }

        int res = Integer.MAX_VALUE;

        // Case 1: Do nothing on the current index
        int noOp = nums[idx]+ recur(opt1, opt2, nums, idx + 1, k, dp);
        res = Math.min(res,noOp);

        // Case 2: Apply op1 on curr idx
        if (opt1 > 0) {
            int halved = (int) Math.ceil(nums[idx] / 2.00);
            int sumop1 = (halved )+ recur(opt1 - 1, opt2, nums, idx + 1, k, dp);
            res = Math.min(res,sumop1);
        }

        // Case 3: Apply op2 on the idx
        if (opt2 > 0 && nums[idx] >= k) {
            int sumop2 =(nums[idx] - k) +recur(opt1, opt2 - 1, nums, idx + 1, k, dp);
            res = Math.min(res,sumop2);

        }

        // Case 4: Apply both op1 and op2 
        if (opt1 > 0 && opt2 > 0) {
            int halved = (int) Math.ceil(nums[idx] / 2.00);

            // First check for halving and subtracting k
            if (halved >= k) {
                int op1  =  (halved -k)+ recur(opt1 - 1, opt2 - 1, nums, idx + 1, k, dp);
                res = Math.min(res,op1);
            }

            // If not, try halving the result after subtracting k from the original number
            if (nums[idx] >= k) {
                int hal = (int) Math.ceil((nums[idx] - k) / 2.00);
                int op2 = hal + recur(opt1 - 1, opt2 - 1, nums, idx + 1, k, dp);
                res = Math.min(op2,res);

            }
        }

        
        dp[idx][opt1][opt2] = res;

        return res;
    }
}