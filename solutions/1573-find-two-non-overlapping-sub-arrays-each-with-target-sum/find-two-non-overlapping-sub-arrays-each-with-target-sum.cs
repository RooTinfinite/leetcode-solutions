public class Solution {
    public int MinSumOfLengths(int[] arr, int target) {
        var pos = new Dictionary<int, int> { [0] = -1 };
        int n = arr.Length, s = 0, ans = n + 1, minL = n;
        for (int i = 0; i < n; i++) {
            s += arr[i];
            if (pos.TryGetValue(s - target, out int j)) {
                int length = i - j;
                ans = Math.Min(ans, length + (j == -1 ? n : arr[j]));
                minL = Math.Min(minL, length);
            }
            arr[i] = minL;
            pos[s] = i;
        }
        return ans == n + 1 ? -1 : ans;
    }
}