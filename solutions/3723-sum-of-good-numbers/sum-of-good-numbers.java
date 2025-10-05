class Solution {
    public int sumOfGoodNumbers(int[] nums, int k) {
        int totalSum = 0; 
        int n = nums.length; 
        
        for (int i = 0; i < n; i++) {
            boolean isGood = true; 
            
            if (i - k >= 0) { 
                if (nums[i] <= nums[i - k]) { 
                    isGood = false; 
                }
            }
            if (i + k < n) { 
                if (nums[i] <= nums[i + k]) { 
                    isGood = false; 
                }
            }
            if (isGood) {
                totalSum += nums[i];
            }
        }
        return totalSum; 
    }
}