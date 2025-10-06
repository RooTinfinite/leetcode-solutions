class Solution {
    private static int recD(int i, int j, int[] arr, int n, Map<Integer, Integer> dp) {
        int key = i * (n + 1) + j;
        if (dp.containsKey(key))
            return dp.get(key);
        
        int ans;
        if (i == n) {
            ans = arr[j];
        }
        else if (i == n - 1) {
            ans = Math.max(arr[j], arr[i]);
        }
        else {
            int op1 = Math.max(arr[j], arr[i]) + recD(i + 2, i + 1, arr, n, dp);
            int op2 = Math.max(arr[j], arr[i+1]) + recD(i + 2, i, arr, n, dp);
            int op3 = Math.max(arr[i], arr[i+1]) + recD(i + 2, j, arr, n, dp);
            ans = Math.min(op1, Math.min(op2, op3));
        }
        
        dp.put(key, ans);
        return ans;
    }
    
    public int minCost(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;

        Map<Integer, Integer> dp = new HashMap<>();
        return recD(1, 0, nums, n, dp);
    }
}