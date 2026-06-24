const MOD: i64 = 1_000_000_007;

#[derive(Clone)]
struct Matrix {
    n: usize,
    m: usize,
    data: Vec<i64>,
}

impl Matrix {
    fn new(n: usize, m: usize) -> Self {
        Matrix {
            n,
            m,
            data: vec![0; n * m],
        }
    }

    fn get(&self, i: usize, j: usize) -> i64 {
        self.data[i * self.m + j]
    }

    fn set(&mut self, i: usize, j: usize, val: i64) {
        self.data[i * self.m + j] = val;
    }

    fn pow_mul(mut self, mut exp: i64, mut res: Matrix) -> Matrix {
        while exp > 0 {
            if exp & 1 == 1 {
                res = &res * &self;
            }
            self = &self * &self;
            exp >>= 1;
        }
        res
    }
}

impl std::ops::Mul for &Matrix {
    type Output = Matrix;

    fn mul(self, b: &Matrix) -> Matrix {
        let mut res = Matrix::new(self.n, b.m);
        for i in 0..self.n {
            for k in 0..self.m {
                let r = self.get(i, k);
                if r == 0 { continue; }

                for j in 0..b.m {
                    res.set(i, j, (res.get(i, j) + r * b.get(k, j)) % MOD);
                }
            }
        }
        res
    }
}

impl Solution {
    pub fn zig_zag_arrays(n: i32, l: i32, r: i32) -> i32 {
        let m = (r - l + 1) as usize;
        if n == 1 { return m as i32; }

        let size = 2 * m;
        let mut u = Matrix::new(size, size);

        for i in 0..m {
            for j in 0..i {
                u.set(i, j + m, 1);
            }
            for j in (i + 1)..m {
                u.set(i + m, j, 1);
            }
        }

        let mut dp = Matrix::new(1, size);
        for i in 0..size {
            dp.set(0, i, 1);
        }

        dp = u.pow_mul((n - 1) as i64, dp);

        let mut ans = 0;
        for i in 0..size {
            ans = (ans + dp.get(0, i)) % MOD;
        }

        ans as i32
    }
}