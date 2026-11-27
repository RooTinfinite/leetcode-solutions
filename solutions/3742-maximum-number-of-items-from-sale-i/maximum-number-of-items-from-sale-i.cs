public class Solution {
    public int MaximumSaleItems(int[][] items, int budget) {
        int[] f = new int[budget + 1];
        int mn = int.MaxValue;
        foreach (var item in items) {
            int factor = item[0], price = item[1];
            mn = Math.Min(mn, price);
            int cnt = 0;
            foreach (var other in items) {
                if (other[0] % factor == 0) {
                    cnt++;
                }
            }
            for (int j = budget; j >= price; j--) {
                f[j] = Math.Max(f[j], f[j - price] + cnt);
            }
        }
        int ans = 0;
        for (int j = 0; j <= budget; j++) {
            ans = Math.Max(ans, f[j] + (budget - j) / mn);
        }
        return ans;
    }
}