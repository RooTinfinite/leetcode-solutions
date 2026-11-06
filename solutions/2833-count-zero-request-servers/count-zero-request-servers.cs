public class Solution {
    public int[] CountServers(int n, int[][] logs, int x, int[] queries) {
        Array.Sort(logs, (a, b) => a[1].CompareTo(b[1]));

        int m = queries.Length;
        int[] ids = Enumerable.Range(0, m).ToArray();
        Array.Sort(ids, (i, j) => queries[i].CompareTo(queries[j]));

        int[] ans = new int[m];
        int[] cnt = new int[n + 1];
        int left = 0, right = 0, active = 0;

        foreach (int i in ids) {
            int q = queries[i];
            while (right < logs.Length && logs[right][1] <= q) {
                int id = logs[right++][0];
                if (cnt[id]++ == 0) {
                    ++active;
                }
            }
            while (left < right && logs[left][1] < q - x) {
                int id = logs[left++][0];
                if (--cnt[id] == 0) {
                    --active;
                }
            }
            ans[i] = n - active;
        }
        return ans;
    }
}