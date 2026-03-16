const MOD: i64 = 1_000_000_007;

struct Fancy {
    v: Vec<i32>,
    a: Vec<i32>,
    b: Vec<i32>,
}

impl Fancy {
    fn new() -> Self {
        Fancy {
            v: Vec::new(),
            a: vec![1],
            b: vec![0],
        }
    }
    
    fn append(&mut self, val: i32) {
        self.v.push(val);
        self.a.push(*self.a.last().unwrap());
        self.b.push(*self.b.last().unwrap());
    }
    
    fn add_all(&mut self, inc: i32) {
        let last_idx = self.b.len() - 1;
        self.b[last_idx] = ((self.b[last_idx] as i64 + inc as i64) % MOD) as i32;
    }
    
    fn mult_all(&mut self, m: i32) {
        let last_idx = self.a.len() - 1;
        self.a[last_idx] = ((self.a[last_idx] as i64 * m as i64) % MOD) as i32;
        self.b[last_idx] = ((self.b[last_idx] as i64 * m as i64) % MOD) as i32;
    }
    
    fn get_index(&self, idx: i32) -> i32 {
        let idx = idx as usize;
        if idx >= self.v.len() {
            return -1;
        }
        
        let ao = ((Self::inv(self.a[idx] as i64) * self.a[self.a.len() - 1] as i64) % MOD) as i64;
        let bo = (self.b[self.b.len() - 1] as i64 - self.b[idx] as i64 * ao % MOD + MOD) % MOD;
        let ans = (ao * self.v[idx] as i64 % MOD + bo) % MOD;
        ans as i32
    }
    
    // fast exponentiation
    fn quick_mul(x: i64, y: i64) -> i64 {
        let mut ret = 1i64;
        let mut cur = x;
        let mut power = y;
        while power != 0 {
            if power & 1 != 0 {
                ret = (ret * cur) % MOD;
            }
            cur = (cur * cur) % MOD;
            power >>= 1;
        }
        ret
    }
    
    // multiplicative inverse
    fn inv(x: i64) -> i64 {
        Self::quick_mul(x, MOD - 2)
    }
}