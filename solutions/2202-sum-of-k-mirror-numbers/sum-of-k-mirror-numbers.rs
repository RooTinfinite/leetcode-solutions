impl Solution {
    pub fn k_mirror(k: i32, mut n: i32) -> i64 {
        let mut a = Palindrome::new(k).peekable();
        let mut b = Palindrome::new(10).peekable();
        let mut ans = 0;
        while n > 0 {
            let (Some(&x), Some(&y)) = (a.peek(), b.peek()) else {
                unreachable!()
            };
            if x <= y {
                a.next();
            }
            if y <= x {
                b.next();
            }
            if x == y {
                ans += x;
                n -= 1;
            }
        }
        ans as i64
    }
}
/// base: 2345
///       |  |
/// res:  2345432  if odd
/// res:  23455432 if even
struct Palindrome {
    n: u8,
    base: Vec<u8>,
    odd: bool,
}
impl Palindrome {
    fn new(n: i32) -> Self {
        Self {
            n: (n) as u8,
            base: vec![0],
            odd: true,
        }
    }
}
impl Iterator for Palindrome {
    type Item = u64;
    fn next(&mut self) -> Option<Self::Item> {
        if let Some(idx) = self.base.iter().position(|x| *x != self.n - 1) {
            self.base[idx] += 1;
            self.base[..idx].iter_mut().for_each(|x| *x = 0);
        } else {
            self.base.iter_mut().for_each(|x| *x = 0);
            if self.odd {
                *self.base.last_mut().unwrap() = 1;
            } else {
                self.base.push(1);
            }
            self.odd = !self.odd;
        };
        Some(
            self.base
                .iter()
                .rev()
                .chain(self.base[if self.odd { 1 } else { 0 }..].iter())
                .fold(0, |acc, &x| acc * self.n as u64 + x as u64),
        )
    }
}