public class Solution {
    public int MinimizedMaximum(int storeCount, int[] productQuantities) {
        int maxQuantity = productQuantities.Max();
        int left = 1;
        int right = maxQuantity;
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (CanDistributeProducts(mid, storeCount, productQuantities)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
    
    private bool CanDistributeProducts(int maxProductsPerStore, int storeCount, int[] quantities) {
        int requiredStores = 0;
        
        foreach (int quantity in quantities) {
            requiredStores += (quantity + maxProductsPerStore - 1) / maxProductsPerStore;
        }
        
        return requiredStores <= storeCount;
    }
}
