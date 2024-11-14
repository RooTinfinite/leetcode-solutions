public class Solution {
    private bool CanDistribute(int x, int[] quantities, int n) {
        int stores = 0;
        foreach (int q in quantities) {
            stores += (int)Math.Ceiling((double)q / x);
        }
        return stores <= n;
    }
    
    public int MinimizedMaximum(int n, int[] quantities) {
        int left = 1;
        int right = quantities.Max();
        int result = 0;
        
        while (left <= right) {
            int x = (left + right) / 2;
            if (CanDistribute(x, quantities, n)) {
                result = x;
                right = x - 1;
            } else {
                left = x + 1;
            }
        }
        
        return result;
    }
}