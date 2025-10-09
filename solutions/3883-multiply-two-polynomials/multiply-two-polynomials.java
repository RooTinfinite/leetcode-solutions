class Solution {
    // time = O((n + m) * log(n + m)), space = O(n + m)
    final double PI = Math.acos(-1);
    int[] rev;
    int bit, tot;
    public long[] multiply(int[] poly1, int[] poly2) {
        int n = poly1.length;
        int m = poly2.length;
        // find bit such that 2^bit >= n + m
        bit = 0;
        while ((1 << bit) < n + m) bit++;
        tot = 1 << bit;

        // dynamically allocate arrays of length tot
        Complex[] a = new Complex[tot];
        Complex[] b = new Complex[tot];
        rev = new int[tot];
        for (int i = 0; i < tot; i++) {
            a[i] = new Complex(0, 0);
            b[i] = new Complex(0, 0);
        }

        // copy input coefficients
        for (int i = 0; i < n; i++) a[i].x = poly1[i];
        for (int j = 0; j < m; j++) b[j].x = poly2[j];

        // build bit-reversal permutation
        for (int i = 0; i < tot; i++) {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
        }

        // forward FFT
        fft(a, 1);
        fft(b, 1);

        // point-wise multiply
        for (int i = 0; i < tot; i++) {
            a[i] = a[i].multiply(b[i]);
        }

        // inverse FFT
        fft(a, -1);

        // collect result and round
        long[] res = new long[n + m - 1];
        for (int i = 0; i < res.length; i++) {
            res[i] = Math.round(a[i].x / tot);
        }
        return res;
    }

    private void fft(Complex[] a, int inv) {
        // bit-reversal reorder
        for (int i = 0; i < tot; i++) {
            if (i < rev[i]) {
                Complex t = a[i];
                a[i] = a[rev[i]];
                a[rev[i]] = t;
            }
        }

        // Cooley–Tukey
        for (int len = 1; len < tot; len <<= 1) {
            double ang = PI / len * inv;
            Complex wlen = new Complex(Math.cos(ang), Math.sin(ang));
            for (int i = 0; i < tot; i += len << 1) {
                Complex w = new Complex(1, 0);
                for (int j = 0; j < len; j++) {
                    Complex u = a[i + j];
                    Complex v = a[i + j + len].multiply(w);
                    a[i + j] = u.plus(v);
                    a[i + j + len] = u.minus(v);
                    w = w.multiply(wlen);
                }
            }
        }
    }

    class Complex {
        private double x, y;
        public Complex(double x, double y) {
            this.x = x;
            this.y = y;
        }

        private Complex plus(Complex t) {
            return new Complex(x + t.x, y + t.y);
        }

        private Complex minus(Complex t) {
            return new Complex(x - t.x, y - t.y);
        }

        private Complex multiply(Complex t) {
            return new Complex(x * t.x - y * t.y, x * t.y + y * t.x);
        }
    }
}