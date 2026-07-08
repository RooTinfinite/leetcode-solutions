class Solution {
    public int countDigitOccurrences(int[] nums, int digit) {
        int cnt = 0;
        for (int n : nums) {
            while (n > 0) {
                if (n % 10 == digit) {
                    cnt++;
                }
                n /= 10;
            }
        }
        return cnt;
    }
}