class Solution {
    public int maxCapacity(int[] costs, int[] capacity, int budget) {
        int n = costs.length;

        // Sort the values by (cost, capacity)
        int[][] pairs = new int[n][2];
        for (int i = 0; i < n; ++i)
            pairs[i] = new int[]{costs[i], capacity[i]};
        Arrays.sort(pairs, (a, b) -> a[0] != b[0] ? (a[0] - b[0]) : (a[1] - b[1]));

        int[] cost_sorted = new int[n], cap_sorted = new int[n];
        for (int i = 0; i < n; ++i) {
            cost_sorted[i] = pairs[i][0];
            cap_sorted[i] = pairs[i][1];
        }

        // Calculate max capacity prefix
        int[] cap_prefix = new int[n];
        for (int i = 0; i < n; ++i)
            cap_prefix[i] = Math.max((i > 0 ? cap_prefix[i - 1] : 0), cap_sorted[i]);

        // One machine
        int result = 0;
        int last_single = lowerBound(cost_sorted, budget) - 1;
        if (last_single >= 0)
            result = cap_prefix[last_single];

        // Two machines
        for (int i = 0; i < n; ++i) {
            int cst = cost_sorted[i];
            if (cst >= budget) // Costs sorted => next ones all >= budget
                break;

            // Try to find another machine to increase capacity with budget left
            int limit = budget - cst;
            int j = lowerBound(cost_sorted, limit) - 1;
            j = Math.min(j, i - 1);

            // If second machine exist, try to update the result
            if (j >= 0)
                result = Math.max(result, cap_sorted[i] + cap_prefix[j]);
        }

        return result;
    }

    private int lowerBound(int[] a, int x) {
        int l = 0, r = a.length;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (a[m] < x) 
                l = m + 1;
            else 
                r = m;
        }
        return l;
    }
}