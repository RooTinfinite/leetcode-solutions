class Solution {
    public long minCuttingCost(int n, int m, int k) {
        long cost = 0;
        
        if (n > k) {
            int parts = n / k;
            int leftover = n - parts * k;
            cost += (long) Math.pow(k, parts) * Math.max(1, leftover);
        }

        if (m > k) {
            int parts = m / k;
            int leftover = m - parts * k;
            cost += (long) Math.pow(k, parts) * Math.max(1, leftover);
        }

        return cost;
    }
}