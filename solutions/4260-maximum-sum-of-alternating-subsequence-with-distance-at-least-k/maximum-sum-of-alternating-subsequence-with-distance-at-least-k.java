import java.util.*;

class SegmentTree {
    long[] tree;
    int n;
    SegmentTree(int n) {
        this.n = n;
        tree = new long[4 * n + 1];
    }
    long pull(long a, long b) {
        return Math.max(a, b);
    }
    long query(int u, int l, int r, int tl, int tr) {
        if (r < tl || l > tr) return 0; // neutral for max
        if (tl <= l && r <= tr) return tree[u];

        int m = (l + r) / 2;
        return pull(
            query(2 * u, l, m, tl, tr),
            query(2 * u + 1, m + 1, r, tl, tr)
        );
    }
    void update(int u, int l, int r, int pos, long val) {
        if (l == r) {
            tree[u] = Math.max(tree[u], val);
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) update(2 * u, l, m, pos, val);
        else update(2 * u + 1, m + 1, r, pos, val);

        tree[u] = pull(tree[2 * u], tree[2 * u + 1]);
    }
    void update(int pos, long val) {
        update(1, 0, n - 1, pos, val);
    }
    long query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
}

class Solution {
    public long maxAlternatingSum(int[] nums, int k) {
        int n = nums.length;
        int mx = 0;
        for (int x : nums) mx = Math.max(mx, x);
        SegmentTree seg0 = new SegmentTree(mx + 1);
        SegmentTree seg1 = new SegmentTree(mx + 1);
        long[] ans0 = new long[n];
        long[] ans1 = new long[n];
        long res = 0;
        // iterate from end
        for (int i = n - 1; i >= 0; i--) {
            if (i + k < n) {
                seg0.update(nums[i + k], ans0[i + k]);
                seg1.update(nums[i + k], ans1[i + k]);
            }
            ans0[i] = nums[i] + seg1.query(nums[i] + 1, mx); // next greater
            ans1[i] = nums[i] + seg0.query(1, nums[i] - 1);  // next smaller
            res = Math.max(res, Math.max(ans0[i], ans1[i]));
        }
        return res;
    }
}