class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        long total = 0;
        int n = costs.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) return a[1] - b[1];
            return a[0] - b[0];
        });

        int left = 0;
        int right = n - 1;

        for (int i = 0; i < candidates; i++) {
            if (left <= right) {
                pq.add(new int[]{costs[left], left});
                left++;
            }
            if (left <= right) {
                pq.add(new int[]{costs[right], right});
                right--;
            }
        }

        for (int i = 0; i < k; i++) {
            int[] top = pq.poll();
            int cost = top[0];
            int index = top[1];
            total += cost;

            if (index < left) {
                if (left <= right) {
                    pq.add(new int[]{costs[left], left});
                    left++;
                }
            } else {
                if (left <= right) {
                    pq.add(new int[]{costs[right], right});
                    right--;
                }
            }
        }

        return total;
    }
}