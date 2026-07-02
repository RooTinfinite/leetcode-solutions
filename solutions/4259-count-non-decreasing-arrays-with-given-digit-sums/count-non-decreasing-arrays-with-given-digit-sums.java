class Solution {

    static final int M = 1000000007;

    int s(int x) {
        int r = 0;
        while (x > 0) {
            r += x % 10;
            x /= 10;
        }

        return r;
    }

    public int countArrays(int[] d) {
        int[] y = d;

        ArrayList<Integer>[] g = new ArrayList[51];
        for (int i = 0; i <= 50; i++)
            g[i] = new ArrayList<>();

        for (int i = 0; i <= 5000; i++) {
            int x = s(i);
            g[x].add(i);
        }

        int n = d.length;

        if (g[d[0]].size() == 0)
            return 0;

        long[] dp = new long[g[d[0]].size()];
        Arrays.fill(dp, 1);

        for (int i = 1; i < n; i++) {
            ArrayList<Integer> p = g[d[i - 1]];
            ArrayList<Integer> c = g[d[i]];

            if (c.size() == 0)
                return 0;

            long[] nd = new long[c.size()];

            long[] pre = new long[p.size()];
            pre[0] = dp[0];
            for (int j = 1; j < p.size(); j++) {
                pre[j] = (pre[j - 1] + dp[j]) % M;
            }

            int k = 0;

            for (int j = 0; j < c.size(); j++) {
                while (k < p.size() && p.get(k) <= c.get(j))
                    k++;
                if (k > 0)
                    nd[j] = pre[k - 1];
            }

            dp = nd;
        }

        long a = 0;
        for (long v : dp)
            a = (a + v) % M;

        return (int) a;

    }
}