public class Solution {
    public int MaxSum(IList<int> nums, int k) {
        const int MOD = 1000000007;
        int[] cnt = new int[30];

        // Count the number of 1 bits at each position
        foreach (int num in nums) {
            for (int i = 0; i < 30; i++) {
                if ((num & (1 << i)) != 0) {
                    cnt[i]++;
                }
            }
        }

        long res = 0;
        for (int i = 0; i < k; i++) {
            long cur = 0;
            // Construct the current number from the most significant bit to the
            // least significant bit
            for (int j = 29; j >= 0; j--) {
                if (cnt[j] > 0) {
                    cur |= (1L << j);
                    cnt[j]--;
                }
            }
            res = (res + cur * cur) % MOD;
        }

        return (int)res;
    }
}