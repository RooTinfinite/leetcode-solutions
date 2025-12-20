class Solution {

    int res = Integer.MAX_VALUE;

    public int minimumScore(int[] nums, int[][] edges) {
        int n = nums.length;
        List<List<Integer>> e = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            e.add(new ArrayList<>());
        }
        for (int[] v : edges) {
            e.get(v[0]).add(v[1]);
            e.get(v[1]).add(v[0]);
        }

        int sum = 0;
        for (int x : nums) {
            sum ^= x;
        }

        dfs(0, -1, nums, e, sum);
        return res;
    }

    private int calc(int part1, int part2, int part3) {
        return (
            Math.max(part1, Math.max(part2, part3)) -
            Math.min(part1, Math.min(part2, part3))
        );
    }

    private int dfs(int x, int f, int[] nums, List<List<Integer>> e, int sum) {
        int son = nums[x];
        for (int y : e.get(x)) {
            if (y == f) {
                continue;
            }
            son ^= dfs(y, x, nums, e, sum);
        }

        for (int y : e.get(x)) {
            if (y == f) {
                dfs2(y, x, son, x, nums, e, sum);
            }
        }
        return son;
    }

    private int dfs2(
        int x,
        int f,
        int oth,
        int anc,
        int[] nums,
        List<List<Integer>> e,
        int sum
    ) {
        int son = nums[x];
        for (int y : e.get(x)) {
            if (y == f) {
                continue;
            }
            son ^= dfs2(y, x, oth, anc, nums, e, sum);
        }
        if (f == anc) {
            return son;
        }
        res = Math.min(res, calc(oth, son, sum ^ oth ^ son));
        return son;
    }
}