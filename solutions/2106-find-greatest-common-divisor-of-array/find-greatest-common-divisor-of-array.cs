public class Solution {
    public int FindGCD(int[] nums) {
        int mx = nums.Max();
        int mn = nums.Min();
        return Gcd(mx, mn);
    }

    private int Gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}