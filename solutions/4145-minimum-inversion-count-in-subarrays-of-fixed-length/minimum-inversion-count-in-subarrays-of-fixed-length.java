import java.util.*;

public class tree {
    int[] t;
    int n;

    tree(int size) {
        n = size;
        t = new int[n + 2];
    }

    void update(int i, int v) {
        while (i < t.length) {
            t[i] += v;
            i += i & -i;
        }
    }

    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += t[i];
            i -= i & -i;
        }
        return res;
    }

    int getquery(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
}

class Solution {
    public long minInversionCount(int[] nums, int k) {
        int n = nums.length;

        int[] s = nums.clone();
        Arrays.sort(s);
        Map<Integer, Integer> rank = new HashMap<>();
        int r = 1;
        for (int x : s) {
            if (!rank.containsKey(x)) {
                rank.put(x, r++);
            }
        }

        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = rank.get(nums[i]);
        }

        int mv = r + 1;
        tree t = new tree(mv);

        long inv = 0;
        for (int i = 0; i < k; i++) {
            inv += t.getquery(c[i] + 1, mv);
            t.update(c[i], 1);
        }

        long mininv = inv;

        for (int i = k; i < n; i++) {
            t.update(c[i - k], -1);
            inv -= t.getquery(1, c[i - k] - 1);

            inv += t.getquery(c[i] + 1, mv);
            t.update(c[i], 1);

            mininv = Math.min(mininv, inv);
        }

        return mininv;
    }
}