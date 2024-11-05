public class Solution {

    private int solve(List<List<Integer>> grid, int val, boolean[] vis) {
        if (vis[val]) {
            return 0;
        }
        int ans = 0;
        vis[val] = true;
        for (int ele : grid.get(val)) {
            if (vis[Math.abs(ele)]) {
                continue;
            }
            if (ele < 0) {
                ans += 1;
            }
            ans += solve(grid, Math.abs(ele), vis);
        }
        return ans;
    }

    public int minReorder(int n, int[][] connections) {
        List<List<Integer>> grid = new ArrayList<>();
        boolean[] vis = new boolean[n];

        for (int i = 0; i < n; i++) {
            grid.add(new ArrayList<>());
        }

        for (int[] conn : connections) {
            int src = conn[0];
            int dest = conn[1];
            grid.get(src).add(-1 * dest);
            grid.get(dest).add(src);
        }

        return solve(grid, 0, vis);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int n = 6;
        int[][] connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
        System.out.println(solution.minReorder(n, connections));
    }
}