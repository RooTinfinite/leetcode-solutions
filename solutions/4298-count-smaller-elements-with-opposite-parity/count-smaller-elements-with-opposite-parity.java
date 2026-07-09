class Solution {
    // time = O(nlogn), space = O(n)
    public int[] countSmallerOppositeParity(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        int[] b = nums.clone();
        Arrays.sort(b);
        HashMap<Integer, Integer> map = new HashMap<>();
        int m = 0;
        for (int x : b) {
            if (!map.containsKey(x)) map.put(x, m++);
        }
        
        Fenwick fen0 = new Fenwick(m);
        Fenwick fen1 = new Fenwick(m);
        for (int i = n - 1; i >= 0; i--) {
            int v = nums[i], idx = map.get(v), p = v % 2;
            if (p == 0) {
                res[i] = fen1.sum(idx);
                fen0.add(idx, 1);
            } else {
                res[i] = fen0.sum(idx);
                fen1.add(idx, 1);
            }
        }
        return res;
    }

    class Fenwick {
        private int n;
        private int[] a;
        public Fenwick(int n) {
            this.n = n;
            this.a = new int[n + 1];
        }

        private void add(int x, int v) {
            for (int i = x + 1; i <= n; i += i & -i) {
                a[i - 1] = a[i - 1] + v;
            }
        }

        private int sum(int x) {
            int ans = 0;
            for (int i = x; i > 0; i -= i & -i) {
                ans = ans + a[i - 1];
            }
            return ans;
        }

        private int rangeSum(int l, int r) { // 左开右闭
            return sum(r) - sum(l);
        }
    }
}