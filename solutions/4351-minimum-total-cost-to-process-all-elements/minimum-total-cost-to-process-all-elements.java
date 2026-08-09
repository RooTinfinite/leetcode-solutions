// AI-converted version of the original C++ solution.
class Solution {
    public int minimumCost(int[] nums, int k) {
        long ops = 0, res = k;

        for (int x : nums) {
            if (res < x) {
                long add = (x - res + k - 1L) / k;
                ops += add;
                res += add * k;
            }
            res -= x;
        }

        final long MOD = 1_000_000_007L;

        if (ops % 2 == 0) {
            return (int) (((ops / 2) % MOD) * ((ops + 1) % MOD) % MOD);
        }

        return (int) ((ops % MOD) * (((ops + 1) / 2) % MOD) % MOD);
    }
}