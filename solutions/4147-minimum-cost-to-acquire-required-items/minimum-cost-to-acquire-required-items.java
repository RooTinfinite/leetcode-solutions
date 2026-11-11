class Solution {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long ans = Long.MAX_VALUE;
        ans = Math.min(ans, (long) need1 * cost1 + (long) need2 * cost2);
        long min = Math.min(need1, need2);
        ans = Math.min(ans, min * costBoth + (long) (need1 - min) * cost1+ (long) (need2 - min) * cost2);
        long max = Math.max(need1, need2);
        ans = Math.min(ans, max * costBoth + (long) Math.max(0, need1 - max) * cost1 + (long) Math.max(0, need2 - max) * cost2);
        return ans;
    }
}