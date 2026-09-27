class Solution {
    public int maxSubarray(int[] nums) {
        int n = nums.length;
        int ans = 0, l = 0;
        int[] hash = new int[501];
        
        for (int r = 0; r < n; ++r) {
            int target = nums[r];
            while (!isValid(target, hash)) {
                hash[nums[l]]--;
                l++;
            }
            hash[nums[r]]++;
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
    
    private boolean isValid(int target, int[] hash) {
        for (int i = 1; i <= target / 2; ++i) {
            if (i == target - i) {
                if (hash[i] >= 2) return false;
            } else {
                if (hash[i] > 0 && hash[target - i] > 0) return false;
            }
        }
        for (int i = 1; i + target <= 500; ++i) {
            if (hash[i] > 0 && hash[i + target] > 0) return false;
        }
        return true;
    }
}