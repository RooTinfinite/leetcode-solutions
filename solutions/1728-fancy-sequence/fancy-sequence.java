class Fancy {

    static final int MOD = 1000000007;
    List<Integer> v;
    List<Integer> a;
    List<Integer> b;

    public Fancy() {
        v = new ArrayList<Integer>();
        a = new ArrayList<Integer>();
        b = new ArrayList<Integer>();
        a.add(1);
        b.add(0);
    }

    public void append(int val) {
        v.add(val);
        a.add(a.get(a.size() - 1));
        b.add(b.get(b.size() - 1));
    }

    public void addAll(int inc) {
        int bLastIndex = b.size() - 1;
        int bLast = b.get(bLastIndex);
        bLast = (bLast + inc) % MOD;
        b.set(bLastIndex, bLast);
    }

    public void multAll(int m) {
        int aLastIndex = a.size() - 1, bLastIndex = b.size() - 1;
        int aLast = (int) (((long) a.get(aLastIndex) * m) % MOD);
        a.set(aLastIndex, aLast);
        int bLast = (int) (((long) b.get(bLastIndex) * m) % MOD);
        b.set(bLastIndex, bLast);
    }

    public int getIndex(int idx) {
        if (idx >= v.size()) {
            return -1;
        }
        int ao = (int) (((long) inv(a.get(idx)) * a.get(a.size() - 1)) % MOD);
        int bo = (int) (((long) b.get(b.size() - 1) -
                ((long) b.get(idx) * ao) % MOD +
                MOD) %
            MOD);
        int ans = (int) (((((long) ao * v.get(idx)) % MOD) + bo) % MOD);
        return ans;
    }

    // fast exponentiation
    private int quickmul(int x, int y) {
        long ret = 1;
        long cur = x;
        while (y != 0) {
            if ((y & 1) != 0) {
                ret = (ret * cur) % MOD;
            }
            cur = (cur * cur) % MOD;
            y >>= 1;
        }
        return (int) ret;
    }

    // multiplicative inverse
    private int inv(int x) {
        return quickmul(x, MOD - 2);
    }
}