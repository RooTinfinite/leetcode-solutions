public class Solution {
    public int[] MaximumBeauty(int[][] items, int[] queries) {
        Array.Sort(items, (a, b) => a[0].CompareTo(b[0]));
        
        int n = items.Length;
        int[] maxBeauties = new int[n];
        maxBeauties[0] = items[0][1];
        
        for(int i = 1; i < n; i++) {
            maxBeauties[i] = Math.Max(maxBeauties[i-1], items[i][1]);
        }
        
        int[] result = new int[queries.Length];
        for(int i = 0; i < queries.Length; i++) {
            int idx = BinarySearch(items, queries[i]);
            result[i] = idx < 0 ? 0 : maxBeauties[idx];
        }
        
        return result;
    }
    
    private int BinarySearch(int[][] items, int target) {
        int left = 0, right = items.Length - 1;
        int result = -1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(items[mid][0] <= target) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
}