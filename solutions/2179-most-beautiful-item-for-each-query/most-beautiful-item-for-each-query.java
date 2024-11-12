class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, (a, b) -> a[0] - b[0]);
        int[][] queriesWithIndex = new int[queries.length][2];
        for (int i = 0; i < queries.length; i++) {
            queriesWithIndex[i] = new int[]{queries[i], i};
        }
        Arrays.sort(queriesWithIndex, (a, b) -> a[0] - b[0]);
        
        int[] res = new int[queries.length];
        int maxBea = 0;
        int j = 0;
        for (int[] query : queriesWithIndex) {
            while (j < items.length && items[j][0] <= query[0]) {
                maxBea = Math.max(maxBea, items[j][1]);
                j++;
            }
            res[query[1]] = maxBea;
        }
        return res;
    }
}