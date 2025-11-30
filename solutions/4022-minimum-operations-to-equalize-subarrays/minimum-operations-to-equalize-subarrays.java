class Solution {
    public long[] minOperations(int[] nums, int k, int[][] queries) {
        final int n = nums.length, m = queries.length;
        final int[] ns = new int[n], pres = new int[n], vs = new int[n+2];
        final int[][] ns2 = new int[n][];
        final SegTree[] sts = new SegTree[n+1];
        for(int i=0,pre=-1;i<n;++i) {
            final int rm = nums[i] % k, t = nums[i] / k;
            if(rm != pre) {
                pres[i] = i;
                pre = rm;
            } else {
                pres[i] = pres[i-1];
            }
            ns2[i] = new int[]{t, i};
        }
        Arrays.sort(ns2, Comparator.comparingInt(a -> a[0]));
        int p = 0;
        for(int i=0;i<n;++i) {
            if(i==0 || ns2[i][0] > ns2[i-1][0]) {
                p++;
                vs[p] = ns2[i][0];
            }
            ns[ns2[i][1]] = p;
        }
        build(ns, sts, p, vs);
        final long[] res = new long[m];
        for(int i=0;i<m;++i) {
            final int l = queries[i][0], r = queries[i][1];
            if(l == r) {
                res[i] = 0L;
            }else if(pres[r] > l) {
                res[i] = -1L;
            }else {
                final int mid = get(sts[l], sts[r+1], (r-l+2) >> 1);
                final long c1 = sts[r+1].getC(1, mid) - sts[l].getC(1, mid), c2 = r - l + 1 - c1;
                final long s1 = sts[r+1].getSum(1, mid) - sts[l].getSum(1, mid), 
                    s2 = mid < p ? (sts[r+1].getSum(mid+1, p) - sts[l].getSum(mid+1, p)) : 0L;
                res[i] = c1 * vs[mid] - s1 + (s2 - c2 * vs[mid]);
            }
        }
        return res;
    }

    private int get(final SegTree pre, final SegTree cur, final int k) {
        if(cur.st == cur.en) {
            return cur.st;
        }
        final int d = cur.left.c - pre.left.c;
        if(d >= k) {
            return get(pre.left, cur.left, k);
        }
        return get(pre.right, cur.right, k - d);
    }

    private void build(final int[] ns, final SegTree[] sts, final int m, final int[] vs) {
        sts[0] = new SegTree(1, m, true);
        for(int i=1;i<=ns.length;++i) {
            final int num = ns[i-1];
            sts[i] = new SegTree(1, m, false);
            int l = 1, r = m;
            SegTree pre = sts[i-1], cur = sts[i];
            while(l < r) {
                cur.c = pre.c + 1;
                cur.sum = pre.sum + vs[num];
                final int mid = (l + r) >> 1;
                if(num <= mid) {
                    cur.right = pre.right;
                    cur.left = new SegTree(l, mid, false);
                    cur = cur.left;
                    pre = pre.left;
                    r = mid;
                } else {
                    cur.left = pre.left;
                    cur.right = new SegTree(mid+1, r, false);
                    cur = cur.right;
                    pre = pre.right;
                    l = mid + 1;
                }
            }
            cur.c = pre.c + 1;
            cur.sum = pre.sum + vs[num];
        }
    }
}

class SegTree{
    int c;
    int st;
    int en;
    long sum;
    SegTree left;
    SegTree right;
    public SegTree(int l, int r, boolean build) {
        st = l;
        en = r;
        sum = 0;
        c = 0;
        left = right = null;
        if(build && st < en) {
            final int mid = (st + en) >> 1;
            left = new SegTree(l, mid, true);
            right = new SegTree(mid+1, r, true);
        }
    }
    public long getSum(final int l, final int r) {
        if(st == l && en == r) {
            return sum;
        }
        final int mid = (st + en) >> 1;
        if(r <= mid) {
            return left.getSum(l, r);
        }else if(l > mid) {
            return right.getSum(l, r);
        }
        return left.getSum(l, mid) + right.getSum(mid+1, r);
    }
    public int getC(final int l, final int r) {
        if(st == l && en == r) {
            return c;
        }
        final int mid = (st + en) >> 1;
        if(r <= mid) {
            return left.getC(l, r);
        }else if(l > mid) {
            return right.getC(l, r);
        }
        return left.getC(l, mid) + right.getC(mid+1, r);
    }
}