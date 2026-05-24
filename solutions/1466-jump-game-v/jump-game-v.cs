public class Solution {
    private int[] f;

    private void Dfs(int[] arr, int id, int d, int n) {
        if (f[id] != -1) {
            return;
        }
        f[id] = 1;
        for (int i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; --i) {
            Dfs(arr, i, d, n);
            f[id] = Math.Max(f[id], f[i] + 1);
        }
        for (int i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
            Dfs(arr, i, d, n);
            f[id] = Math.Max(f[id], f[i] + 1);
        }
    }

    public int MaxJumps(int[] arr, int d) {
        int n = arr.Length;
        f = new int[n];
        Array.Fill(f, -1);
        for (int i = 0; i < n; ++i) {
            Dfs(arr, i, d, n);
        }
        return f.Max();
    }
}