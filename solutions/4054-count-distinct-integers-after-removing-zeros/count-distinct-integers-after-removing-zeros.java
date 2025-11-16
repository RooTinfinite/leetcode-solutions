class Solution {
    public long countDistinct(long n) {
        String s = Long.toString(n);
        int len = s.length();
        long ans = 0;
        long[] p = new long[len+1];
        for (int i = 0; i <= len; ++i) p[i] = 1;
        for (int i = 1; i <= len; ++i) p[i] = p[i-1] * 9;
        for (int l = 1; l < len; ++l) ans += p[l];
        for (int i = 0; i < len; ++i) {
            int d = s.charAt(i) - '0';
            if (d == 0) return ans;
            ans += (long)(d - 1) * p[len - i - 1];
        }
        long res = ans + 1;
        return res;
    }
}