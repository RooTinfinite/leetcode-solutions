class Solution {

    static final long MOD1 = 1000000007L;
    static final long MOD2 = 1000000009L;

    static final long BASE1 = 911382323L;
    static final long BASE2 = 972663749L;

    long[] h1, h2, p1, p2;

    private long get(long[] h, long[] p, long mod, int l, int r) {
        return (h[r] - (h[l] * p[r - l]) % mod + mod) % mod;
    }

    private boolean ok(int len, int[] nums) {
        int n = nums.length;
        HashMap<Long, Integer> mp = new HashMap<>();

        for (int i = 0; i + len <= n; i++) {
            long a = get(h1, p1, MOD1, i, i + len);
            long b = get(h2, p2, MOD2, i, i + len);

            long key = (a << 32) ^ b;

            mp.put(key, mp.getOrDefault(key, 0) + 1);
        }

        for (int v : mp.values()) {
            if (v == 1) {
                return true;
            }
        }

        return false;
    }

    public int smallestUniqueSubarray(int[] nums) {
        int n = nums.length;

        h1 = new long[n + 1];
        h2 = new long[n + 1];

        p1 = new long[n + 1];
        p2 = new long[n + 1];

        p1[0] = 1;
        p2[0] = 1;

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE1 + nums[i] + 1) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + nums[i] + 1) % MOD2;

            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
        }

        int lo = 1;
        int hi = n;
        int res = n;

        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (ok(mid, nums)) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return res;
    }
}