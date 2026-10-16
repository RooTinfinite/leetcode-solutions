public class BIT {
    public int size;
    public long[] _tree1;
    public long[] _tree2;

    public BIT(int n) {
        this.size = n;
        this._tree1 = new long[n + 2];
        this._tree2 = new long[n + 2];
    }

    private int _lowbit(int index) {
        return index & -index;
    }

    public void add(int left, int right, int delta) {
        _add(left, delta);
        _add(right + 1, -delta);
    }

    public long query(int left, int right) {
        return _query(right) - _query(left - 1);
    }

    private void _add(int index, int delta) {
        index += 1;
        long rawIndex = index;
        while (index <= size) {
            _tree1[index] += delta;
            _tree2[index] += rawIndex * delta;
            index += _lowbit(index);
        }
    }

    private long _query(int index) {
        index += 1;
        long rawIndex = index + 1;
        if (index > size) {
            index = size;
        }
        long res = 0;
        while (index > 0) {
            res += rawIndex * _tree1[index] - _tree2[index];
            index -= _lowbit(index);
        }
        return res;
    }
}

public class Solution {
    public int SumCounts(int[] A) {
        int n = A.Length;
        long res = 0, cur = 0;
        BIT bit = new BIT(n + 10);
        Dictionary<int, int> seen = new Dictionary<int, int>();
        long mod = 1000000007;
        for (int i = 0; i < n; i++) {
            int a = A[i];
            int j = (seen.ContainsKey(a) ? seen[a] : -1) + 1;
            long q = bit.query(j, i);
            cur = (cur + q * 2 + i - j + 1) % mod;
            res = (res + cur) % mod;
            bit.add(j, i, 1);
            seen[a] = i;
        }
        return (int)res;
    }
}