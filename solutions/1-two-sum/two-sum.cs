public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> ht = new Dictionary<int, int>();
        
        for (int i = 0; i < nums.Length; i++) {
            int tmp = nums[i];
            
            if (ht.ContainsKey(target - tmp)) {
                return new int[] {ht[target - tmp], i};
            }
            
            ht[tmp] = i;
        }
        
        return new int[0];
    }
}