class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        boolean[] ans = new boolean[queries.length];
        int[] count = new int[nums.length];
        for (int i = 0; i < nums.length - 1; ++i) {
            count[i+1] += count[i];
            if ( (nums[i]&1 ) != (nums[i+1]&1) )
                count[i+1] += 1;
        }
        for (int i = 0; i < queries.length; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            if (count[end] - count[start] == end - start) ans[i] = true;
            else ans[i] = false;
        }
        return ans;
    }
}