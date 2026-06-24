public class Solution {
    const long MOD = 1_000_000_007;

    public struct Matrix {
        public int n, m;
        public long[] data;

        public Matrix(int n, int m) {
            this.n = n;
            this.m = m;
            data = new long[n * m];
        }

        public long Get(int i, int j) => data[i * m + j];
        public void Set(int i, int j, long val) => data[i * m + j] = val;

        public static Matrix operator*(Matrix a, Matrix b) {
            var res = new Matrix(a.n, b.m);

            for (var i = 0; i < a.n; i++) {
                for (var k = 0; k < a.m; k++) {
                    var r = a.Get(i, k);
                    if (r == 0)
                        continue;

                    for (var j = 0; j < b.m; j++) {
                        res.Set(i, j, (res.Get(i, j) + r * b.Get(k, j)) % MOD);
                    }
                }
            }
            return res;
        }

        public Matrix PowMul(long exp, Matrix res) {
            var baseMat = new Matrix(n, m);
            Array.Copy(data, baseMat.data, data.Length);

            while (exp > 0) {
                if ((exp & 1) == 1) {
                    res *= baseMat;
                }
                baseMat *= baseMat;
                exp >>= 1;
            }
            return res;
        }
    }

    public int ZigZagArrays(int n, int l, int r) {
        if (n == 1)
            return r - l + 1;

        var m = r - l + 1;
        var size = 2 * m;
        var u = new Matrix(size, size);

        for (var i = 0; i < m; i++) {
            for (var j = 0; j < i; j++) u.Set(i, j + m, 1);
            for (var j = i + 1; j < m; j++) u.Set(i + m, j, 1);
        }

        var dp = new Matrix(1, size);
        Array.Fill(dp.data, 1L);

        dp = u.PowMul(n - 1, dp);

        return (int)dp.data.Aggregate(0L, (acc, val) => (acc + val) % MOD);
    }
}