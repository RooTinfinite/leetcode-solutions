class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        // Step 1: Sort items by price in ascending order
        Arrays.sort(items, (a, b) -> Integer.compare(a[0], b[0]));
        
        int n = items.length;
        // Step 2: Extract prices and beauties into separate arrays
        int[] prices = new int[n];
        int[] beauties = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = items[i][0];
            beauties[i] = items[i][1];
        }
        
        // Step 3: Create running maximum beauty array
        int[] maxBeauties = new int[n + 1];
        for (int i = 0; i < n; i++) {
            maxBeauties[i + 1] = Math.max(maxBeauties[i], beauties[i]);
        }
        
        // Step 4: Process each query using binary search
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int index = upperBound(prices, queries[i]);
            result[i] = maxBeauties[index];
        }
        
        return result;
    }
    
    // Helper method for binary search
    private int upperBound(int[] arr, int target) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
}