class Solution {
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public int resilientSubarray(int[] nums, int k) {
        int n = nums.length;
        int ans = 1;
        int i = 0;
        
        while (i < n) {
            int r = nums[i] % k;
            int j = i;
            
            while (j < n && nums[j] % k == r) {
                j++;
            }
            
            int m = j - i;
            int d = k / gcd(r, k);
            int l = ((m - 1) / d) * d + 1;
            
            ans = Math.max(ans, l);
            i = j;
        }
        
        return ans;
    }
}