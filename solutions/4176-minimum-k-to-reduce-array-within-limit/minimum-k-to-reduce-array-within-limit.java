class Solution {
    private long nonPositive(int[] a, int n, int k) {
        long ops = 0;
        for (int i = 0; i < n; i++)
            ops += (a[i] + k - 1L) / k;
        return ops;
    }

    public int minimumK(int[] nums) {
        int n0 = nums.length;

        // Filter <= 0
        int[] a = new int[n0];
        int n = 0, mx = 0;
        for (int x : nums) {
            if (x > 0) {
                a[n++] = x;
                if (x > mx) 
                    mx = x;
            }
        }
        if (n == 0) 
            return 0;

        int l = 1, r = mx > n ? mx : n;

        while (l < r) {
            int m = l + (r - l) / 2;
            long ops = nonPositive(a, n, m);
            long mm = 1L * m * m;
            if (ops <= mm) 
                r = m;
            else 
                l = m + 1;
        }
        return l;
    }
}