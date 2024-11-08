public class Solution {
    public int[] GetMaximumXor(int[] nums, int maximumBit) {
        int mask = (1 << maximumBit) - 1;
        int n = nums.Length;
        int[] res = new int[n];
        int curr = 0;
        
        for(int i = 0; i < n; i++) {
            curr ^= nums[i];
            res[n-i-1] = ~curr & mask;
        }
        
        return res;
    }
}