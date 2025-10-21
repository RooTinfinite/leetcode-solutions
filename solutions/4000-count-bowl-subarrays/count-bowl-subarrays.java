class Solution {
    public long bowlSubarrays(int[] nums) {
        long res = 0;
        java.util.List<Integer> stk = new java.util.ArrayList<>();
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            while (!stk.isEmpty() && nums[stk.get(stk.size() - 1)] < nums[i]) {
                if (i - stk.get(stk.size() - 1) >= 2) {
                    res++;
                }
                stk.remove(stk.size() - 1);
            }
            if (!stk.isEmpty() && i - stk.get(stk.size() - 1) >= 2) {
                res++;
            }
            stk.add(i);
        }
        return res;
    }
}