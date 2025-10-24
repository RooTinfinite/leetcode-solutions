import java.util.*;

public class Solution {
    static final int MOD = 1_000_000_007;

    public int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;         // number of values
        int size = 2 * m;          // total state space

        if (n == 1) return m;

        // Build transition matrix T
        long[][] T = new long[size][size];

        for (int i = 0; i < m; i++) {
            // from down, i → up, j for j < i
            for (int j = 0; j < i; j++) {
                T[i][j + m] = 1;
            }

            // from up, i → down, j for j > i
            for (int j = i + 1; j < m; j++) {
                T[i + m][j] = 1;
            }
        }

        // Exponentiate T^(n - 1)
        long[][] Tn = matrixPower(T, n - 1);

        // Initial vector v0: all ones
        long[] v0 = new long[size];
        Arrays.fill(v0, 1L);

        // Multiply Tn * v0
        long[] result = multiplyMatrixVector(Tn, v0);

        // Sum all entries
        long total = 0;
        for (long val : result) total = (total + val) % MOD;

        return (int) total;
    }

    private long[][] matrixPower(long[][] mat, int exp) {
        int n = mat.length;
        long[][] res = new long[n][n];

        // Initialize res as identity matrix
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp > 0) {
            if ((exp & 1) == 1) {
                res = multiplyMatrices(res, mat);
            }
            mat = multiplyMatrices(mat, mat);
            exp >>= 1;
        }

        return res;
    }

    private long[][] multiplyMatrices(long[][] A, long[][] B) {
        int n = A.length;
        long[][] res = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    private long[] multiplyMatrixVector(long[][] mat, long[] vec) {
        int n = mat.length;
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            long sum = 0;
            for (int j = 0; j < n; j++) {
                sum = (sum + mat[i][j] * vec[j]) % MOD;
            }
            res[i] = sum;
        }
        return res;
    }
}