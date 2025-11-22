class Solution {
    public long totalWaviness(long num1, long num2) {
        long a = getWaviness(num1 - 1);
        long b = getWaviness(num2);
        return b - a;
    }

    public long getWaviness(long num) {
        char[] chrs = String.valueOf(num).toCharArray();
        long[] DP_first = new long[10];
        long[] DP_inc = new long[10];
        long[] DP_dec = new long[10];
        long res = 0;
        int prv = 0;
        int slope = 0;
        long base = (long) Math.pow(10, chrs.length - 1);
        for (int i = 0; i < chrs.length; i++) {
            int digit = chrs[i] - '0';
            long[] DP_first_next = new long[10];
            long[] DP_inc_next = new long[10];
            long[] DP_dec_next = new long[10];
            long remain = num % base+1;
            if (i > 0) {
                for (int j = 1; j < 10; j++) {
                    DP_first_next[j] += 1;
                }
                for (int j = 0; j < digit; j++) {
                    if (j > prv) {
                        DP_inc_next[j] += 1;
                        if (slope == -1)
                            res += base;
                    } else if (j < prv) {
                        DP_dec_next[j] += 1;
                        if (slope == 1)
                            res += base;
                    } else {
                        DP_first_next[j] += 1;
                    }
                }
            } else {
                for (int j = 1; j < digit; j++) {
                    DP_first_next[j] += 1;
                }
            }

            if (i == 0) {
                prv = digit;
            } else if (i == 1) {
                if (digit > prv) {
                    slope = 1;
                } else if (digit < prv) {
                    slope = -1;
                } else {
                    slope = 0;
                }
                prv = digit;
            } else {
                if (digit > prv) {
                    if (slope == -1)
                        res += remain;
                    slope = 1;
                } else if (digit < prv) {
                    if (slope == 1)
                        res += remain;
                    slope = -1;
                } else {
                    slope = 0;
                }
                prv = digit;
            }

            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    if (j < k) {
                        res += base * DP_dec[j];
                        DP_inc_next[k] += DP_first[j] + DP_inc[j] + DP_dec[j];
                    } else if (j > k) {
                        res += base * DP_inc[j];
                        DP_dec_next[k] += DP_first[j] + DP_inc[j] + DP_dec[j];
                    } else {
                        DP_first_next[k] += DP_first[j] + DP_inc[j] + DP_dec[j];
                    }
                }
            }
            DP_first = DP_first_next;
            DP_inc = DP_inc_next;
            DP_dec = DP_dec_next;
            base /= 10;
        }
        return res;
    }
}