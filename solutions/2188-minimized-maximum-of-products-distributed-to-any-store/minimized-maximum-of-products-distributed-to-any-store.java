class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        int res = 0;
        int left = 1;
        int right = getMax(quantities);
        
        while (left <= right) {
            int x = (left + right) / 2;
            if (canDistribute(x, n, quantities)) {
                res = x;
                right = x - 1;
            } else {
                left = x + 1;
            }
        }
        
        return res;
    }
    
    private boolean canDistribute(int x, int n, int[] quantities) {
        int stores = 0;
        for (int q : quantities) {
            stores += (q + x - 1) / x; // Math.ceil equivalent in Java
        }
        return stores <= n;
    }
    
    private int getMax(int[] quantities) {
        int max = quantities[0];
        for (int q : quantities) {
            max = Math.max(max, q);
        }
        return max;
    }
}