public class Fancy {
    const int MOD = 1000000007;
    List<int> v;
    List<int> a;
    List<int> b;

    public Fancy() {
        v = new List<int>();
        a = new List<int>();
        b = new List<int>();
        a.Add(1);
        b.Add(0);
    }

    public void Append(int val) {
        v.Add(val);
        a.Add(a[a.Count - 1]);
        b.Add(b[b.Count - 1]);
    }

    public void AddAll(int inc) {
        int lastIndex = b.Count - 1;
        int lastB = (b[lastIndex] + inc) % MOD;
        b[lastIndex] = lastB;
    }

    public void MultAll(int m) {
        int lastIndex = a.Count - 1;
        long lastA = ((long)a[lastIndex] * m) % MOD;
        a[lastIndex] = (int)lastA;

        long lastB = ((long)b[lastIndex] * m) % MOD;
        b[lastIndex] = (int)lastB;
    }

    public int GetIndex(int idx) {
        if (idx >= v.Count) {
            return -1;
        }

        long ao = ((long)Inv(a[idx]) * a[a.Count - 1]) % MOD;
        long bo = (b[b.Count - 1] - (long)b[idx] * ao % MOD + MOD) % MOD;
        long ans = (ao * v[idx] % MOD + bo) % MOD;
        return (int)ans;
    }

    // fast exponentiation
    private int QuickMul(int x, int y) {
        long ret = 1;
        long cur = x;
        while (y != 0) {
            if ((y & 1) != 0) {
                ret = ret * cur % MOD;
            }
            cur = cur * cur % MOD;
            y >>= 1;
        }
        return (int)ret;
    }

    // multiplicative inverse
    private int Inv(int x) {
        return QuickMul(x, MOD - 2);
    }
}