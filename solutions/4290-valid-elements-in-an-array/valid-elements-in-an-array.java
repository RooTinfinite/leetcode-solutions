import java.util.*;

class Solution {
    public List<Integer> findValidElements(int[] nums) {
        int n = nums.length;
        boolean[] prefix = new boolean[n];
        prefix[0] = true;
        prefix[n-1] = true;
        
        int maxEle = nums[0];
        for (int i = 1; i < n-1; i++) {
            if (nums[i] > maxEle) {
                maxEle = nums[i];
                prefix[i] = true;
            }
        }
        
        maxEle = nums[n-1];
        for (int i = n-2; i > 0; i--) {
            if (nums[i] > maxEle) {
                maxEle = nums[i];
                prefix[i] = true;
            }
        }
        
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (prefix[i]) ans.add(nums[i]);
        }
        return ans;
    }
}