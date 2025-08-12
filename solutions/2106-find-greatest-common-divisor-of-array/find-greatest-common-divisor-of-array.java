class Solution {
    public int findGCD(int[] nums) {
        int mn = nums[0], mx = nums[0];
        for (int x : nums) {
            if (x < mn) mn = x;
            if (x > mx) mx = x;
        }
        int a = mn, b = mx;
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
}