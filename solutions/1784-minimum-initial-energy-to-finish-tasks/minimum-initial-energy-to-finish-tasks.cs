public class Solution {
    public int MinimumEffort(int[][] tasks) {
        Array.Sort(tasks, (a, b) => (b[1] - b[0]).CompareTo(a[1] - a[0]));
        int ans = 0;
        int remain = 0;
        foreach (int[] task in tasks) {
            if (remain <= task[1]) {
                ans += task[1] - remain;
            }
            remain = Math.Max(task[1] - task[0], remain - task[0]);
        }
        return ans;
    }
}