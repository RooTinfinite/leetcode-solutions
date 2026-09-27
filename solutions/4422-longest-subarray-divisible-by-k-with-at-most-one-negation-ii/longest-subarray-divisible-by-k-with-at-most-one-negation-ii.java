class Solution {
    public int longestSubarray(int[] nums, int k) {
        int n = nums.length;
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) prefix[i + 1] = Math.floorMod(prefix[i] + nums[i], k);

        int[] first = new int[k], last = new int[k];
        Arrays.fill(first, n + 1);
        Arrays.fill(last, -1);
        for (int i = 0; i <= n; i++) last[prefix[i]] = i;
        for (int i = n; i >= 0; i--) first[prefix[i]] = i;

        int best = 0;
        for (int c = 0; c < k; c++) best = Math.max(best, last[c] - first[c]);   // no negation

        int[] doubled = new int[n];
        for (int i = 0; i < n; i++) doubled[i] = Math.floorMod(2 * nums[i], k);

        Integer[] order = new Integer[k];
        for (int c = 0; c < k; c++) order[c] = c;
        Arrays.sort(order, (a, b) -> first[b] - first[a]);

        int[] nxt = new int[k];
        Arrays.fill(nxt, n + 1);
        int i = n - 1;
        for (int c : order) {
            int start = first[c];
            if (start > n) continue;
            for (; i >= start; i--) nxt[doubled[i]] = i;
            for (int v = 0; v < k; v++) {
                int end = last[(c + v) % k];
                if (nxt[v] < end) best = Math.max(best, end - start);
            }
        }
        return best;
    }
}