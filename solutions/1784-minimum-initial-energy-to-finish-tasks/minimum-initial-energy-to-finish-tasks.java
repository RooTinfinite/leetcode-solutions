class Solution {

    public int minimumEffort(int[][] tasks) {
        Arrays.sort(tasks, (a, b) -> (b[1] - b[0]) - (a[1] - a[0]));
        int ans = 0;
        int remain = 0;
        for (int[] task : tasks) {
            if (remain <= task[1]) {
                ans += task[1] - remain;
            }
            remain = Math.max(task[1] - task[0], remain - task[0]);
        }
        return ans;
    }
}