import java.util.*;

class Solution {
    int[][][][] dp;

    public int sol(List<Integer> p, List<Integer> t, int i, int k, int pt, int nt) {
        int n = p.size();
        if (i >= n) {
            if (k != 0)
                return (int) 1e8;
            else
                return 0;
        }
        if (dp[i][k][pt][nt] != -1)
            return dp[i][k][pt][nt];

        int ans = ((p.get(i) - p.get(i - 1)) * pt) + sol(p, t, i + 1, k, nt, t.get(i + 1));
        if (k > 0 && i < n - 1) {
            int tans = ((p.get(i) - p.get(i - 1)) * pt) + sol(p, t, i + 1, k - 1, pt, t.get(i + 1) + nt);
            ans = Math.min(ans, tans);
        }
        return dp[i][k][pt][nt] = ans;
    }
    public int minTravelTime(int l, int n, int k, int[] pArr, int[] tArr) 
    {
        List<Integer> p = new ArrayList<>();
        for (int x : pArr) p.add(x);
        List<Integer> t = new ArrayList<>();
        for (int x : tArr) t.add(x);
        dp = new int[n + 1][k + 1][101][101];
        for (int[][][] a : dp)
            for (int[][] b : a)
                for (int[] c : b)
                    Arrays.fill(c, -1);
        t.add(t.get(t.size() - 1));
        return sol(p, t, 1, k, t.get(0), t.get(1));
    }
}
