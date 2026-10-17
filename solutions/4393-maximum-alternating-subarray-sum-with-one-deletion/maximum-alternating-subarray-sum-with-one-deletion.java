class Solution {
    public long maxAlternatingSum(int[] nums) {
        final long NEG = Long.MIN_VALUE / 2;
        long ans = NEG, plus = NEG, minus = NEG, plusDel = NEG, minusDel = NEG;
        for (long x : nums) {
            long p = Math.max(x, minus + x);  // start fresh at x, or add x after a minus
            long m = plus - x;  // subtract x after a plus
            long pd = Math.max(minusDel + x, plus);  // add x after a minus with deletion used, or delete x
            long md = Math.max(plusDel - x, minus);  // subtract x after a plus with deletion used, or delete x
            plus = p; minus = m; plusDel = pd; minusDel = md;
            ans = Math.max(ans, Math.max(Math.max(plus, minus), Math.max(plusDel, minusDel)));
        }
        return ans;
    }
}