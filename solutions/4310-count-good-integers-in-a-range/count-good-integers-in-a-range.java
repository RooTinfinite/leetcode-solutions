class Solution {
    long[][][] dp;
    
    long get(String s, int n, int i, int prev, boolean small, int k) {
        if (i == n) return 1;
        
        int smallIdx = small ? 1 : 0;
        if (dp[i][prev][smallIdx] != -1) return dp[i][prev][smallIdx];
        
        long res = 0;
        int start = Math.max(0, prev - k);
        int end = Math.min(9, prev + k);
        if (small == false) end = Math.min(end, s.charAt(i) - '0');
        
        for (int j = start; j <= end; j++) {
            res += get(s, n, i + 1, j, small || (j < (s.charAt(i) - '0')), k);
        }
        return dp[i][prev][smallIdx] = res;
    }
    
    long f(long num, long k) {
        dp = new long[16][10][2];
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 10; j++) {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }

        String s = Long.toString(num);
        int n = s.length();
        long res = 0;
        for (int len = 0; len < n; len++) {
            int mx = (len == 0 ? s.charAt(0) - '0' : 9);
            for (int prev = 1; prev <= mx; prev++) {
                if (len == 0 && prev == mx) {
                    res += get(s, n, len + 1, prev, false, (int)k);
                } else {
                    res += get(s, n, len + 1, prev, true, (int)k);
                }
            }
        }
        return res;
    }
    
    public long goodIntegers(long l, long r, int k) {
        return f(r, k) - f(l - 1, k);
    }
}