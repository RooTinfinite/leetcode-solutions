class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, (a, b) -> a[0] - b[0]);
        
        int n = items.length;
        int[] maxBeauties = new int[n];
        maxBeauties[0] = items[0][1];
        
        // Precompute maximum beauties
        for (int i = 1; i < n; i++) {
            maxBeauties[i] = Math.max(maxBeauties[i-1], items[i][1]);
        }
        
        int[] result = new int[queries.length];
        
        // Binary search for each query
        for (int i = 0; i < queries.length; i++) {
            int idx = binarySearch(items, queries[i]);
            result[i] = idx < 0 ? 0 : maxBeauties[idx];
        }
        
        return result;
    }
    
    private int binarySearch(int[][] items, int target) {
        int left = 0;
        int right = items.length - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (items[mid][0] <= target) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
}