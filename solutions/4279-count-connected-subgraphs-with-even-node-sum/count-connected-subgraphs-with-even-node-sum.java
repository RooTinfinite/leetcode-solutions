class Solution {
    List<List<Integer>> subsets = new ArrayList<>();

    class DSU {
        int[] parent;
        int[] rank;

        public DSU(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        public int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }

        public void union(int a, int b) {
            int pa = find(a);
            int pb = find(b);
            if (pa == pb) return;

            if (rank[pa] < rank[pb]) {
                parent[pa] = pb;
            } else if (rank[pa] > rank[pb]) {
                parent[pb] = pa;
            } else {
                parent[pb] = pa;
                rank[pa]++;
            }
        }
    }

    public int evenSumSubgraphs(int[] nums, int[][] edges) {
        subsets.clear();
        generate(0, nums.length, new ArrayList<>());

        int count = 0;

        for (List<Integer> sub : subsets) {
            if (sub.size() == 0) continue;

            int sum = 0;
            for (int node : sub) sum += nums[node];
            if (sum % 2 != 0) continue;

            HashSet<Integer> set = new HashSet<>(sub);
            DSU dsu = new DSU(nums.length);

            for (int[] e : edges) {
                int u = e[0], v = e[1];
                if (set.contains(u) && set.contains(v)) {
                    dsu.union(u, v);
                }
            }

            HashSet<Integer> parents = new HashSet<>();
            for (int x : sub) {
                parents.add(dsu.find(x));
            }

            if (parents.size() == 1) count++;
        }

        return count;
    }

    public void generate(int i, int n, List<Integer> curr) {
        subsets.add(new ArrayList<>(curr));

        for (int idx = i; idx < n; idx++) {
            curr.add(idx);
            generate(idx + 1, n, curr);
            curr.remove(curr.size() - 1);
        }
    }
}