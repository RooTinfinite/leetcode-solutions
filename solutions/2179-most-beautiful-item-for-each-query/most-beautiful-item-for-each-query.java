class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, (a,b) -> a[0] - b[0]); // Sort by price
        TreeMap<Integer, Integer> priceToBeauty = new TreeMap<>(); // Track max beauty at each price point
        int maxBeauty = 0;
        for(int[] item: items) {
            maxBeauty = Math.max(maxBeauty, item[1]);
            priceToBeauty.put(item[0], maxBeauty);
        }
        int[] result = new int[queries.length]; // Process queries using floor key
        for(int i = 0; i < queries.length; i++) {
            Integer key = priceToBeauty.floorKey(queries[i]);
            result[i] = key == null ? 0 : priceToBeauty.get(key);
        }
        return result;
    }
}