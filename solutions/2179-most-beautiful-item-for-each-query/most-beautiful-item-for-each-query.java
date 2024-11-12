class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        // Sort items by price
        Arrays.sort(items, (price1, price2) -> price1[0] - price2[0]);
        
        int currentMaxBeauty = 0;
        TreeMap<Integer, Integer> priceToBeautyMap = new TreeMap<>();
        
        // Build price to beauty mapping
        for (int[] item : items) {
            int price = item[0];
            int beauty = item[1];
            currentMaxBeauty = Math.max(currentMaxBeauty, beauty);
            priceToBeautyMap.put(price, currentMaxBeauty);
        }
        
        int[] beautyResults = new int[queries.length];
        int resultIndex = 0;
        
        // Process each price query
        for (int queryPrice : queries) {
            Integer nearestPrice = priceToBeautyMap.floorKey(queryPrice);
            beautyResults[resultIndex++] = (nearestPrice == null) ? 0 : priceToBeautyMap.get(nearestPrice);
        }
        
        return beautyResults;
    }
}