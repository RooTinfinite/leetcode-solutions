class Solution {
    public int longestSubsequence(int[] nums) {
        int N = nums.length;
        int s = 0;
        boolean flag = true;
        
        for (int n : nums) {
            s ^= n;
            if (n != 0) {
                flag = false;
            }
        }
        
        // All elements are zero
        if (flag) {
            return 0;
        }
        
        // XOR of all elements is zero - remove one element
        if (s == 0) {
            return N - 1;
        }
        
        // XOR of all elements is non-zero - take entire array
        return N;
    }
}