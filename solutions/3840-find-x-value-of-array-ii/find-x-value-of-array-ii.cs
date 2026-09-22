public class SegmentTree {
    private const int MAXK = 6;
    private int k;
    private int n;
    private int[][] tree;

    public SegmentTree(int[] nums, int k) {
        this.k = k;
        this.n = nums.Length;
        int size = 2 << (Convert.ToString(n, 2).Length);
        tree = new int [size][];
        for (int i = 0; i < size; i++) {
            tree[i] = new int[MAXK];
        }
        Build(nums, 1, 0, n - 1);
    }

    private void MakeLeaf(int o, int value) {
        Array.Fill(tree[o], 0);
        int r = value % k;
        tree[o][r] = 1;
        tree[o][k] = r;
    }

    private void MergePre(int[] left, int[] right, int[] result) {
        int mulL = left[k];
        int mulR = right[k];
        result[k] = (mulL * mulR) % k;

        for (int x = 0; x < k; x++) {
            result[x] = left[x];
        }
        for (int x = 0; x < k; x++) {
            result[(mulL * x) % k] += right[x];
        }
    }

    private void Maintain(int o) {
        MergePre(tree[o * 2], tree[o * 2 + 1], tree[o]);
    }

    private void Build(int[] nums, int o, int l, int r) {
        if (l == r) {
            MakeLeaf(o, nums[l]);
            return;
        }
        int m = (l + r) / 2;
        Build(nums, o * 2, l, m);
        Build(nums, o * 2 + 1, m + 1, r);
        Maintain(o);
    }

    public void Update(int o, int l, int r, int index, int value) {
        if (l == r) {
            MakeLeaf(o, value);
            return;
        }
        int m = (l + r) / 2;
        if (index <= m) {
            Update(o * 2, l, m, index, value);
        } else {
            Update(o * 2 + 1, m + 1, r, index, value);
        }
        Maintain(o);
    }

    public int[] Query(int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return tree[o];
        }

        int m = (l + r) / 2;
        if (R <= m) {
            return Query(o * 2, l, m, L, R);
        }
        if (L > m) {
            return Query(o * 2 + 1, m + 1, r, L, R);
        }

        int[] left = Query(o * 2, l, m, L, R);
        int[] right = Query(o * 2 + 1, m + 1, r, L, R);
        int[] result = new int[MAXK];
        MergePre(left, right, result);
        return result;
    }
}

public class Solution {
    public int[] ResultArray(int[] nums, int k, int[][] queries) {
        int n = nums.Length;
        SegmentTree seg = new SegmentTree(nums, k);
        int[] ans = new int[queries.Length];

        for (int i = 0; i < queries.Length; i++) {
            int[] q = queries[i];
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            seg.Update(1, 0, n - 1, index, value);
            int[] pre = seg.Query(1, 0, n - 1, start, n - 1);
            ans[i] = pre[x];
        }

        return ans;
    }
}