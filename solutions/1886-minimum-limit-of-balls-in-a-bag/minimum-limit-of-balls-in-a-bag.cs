public class Solution {
    private bool CanDivide(int[] nums, int maxBalls, int maxOperations) {
        int ops = 0;
        foreach (int n in nums) {
            ops += (n + maxBalls - 1) / maxBalls - 1;
            if (ops > maxOperations) return false;
        }
        return true;
    }
    
    public int MinimumSize(int[] nums, int maxOperations) {
        int left = 1, right = nums.Max();
        int res = right;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (CanDivide(nums, mid, maxOperations)) {
                right = mid;
                res = right;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
}