use core::arch::x86_64::_pdep_u64;

impl Solution {
    pub fn min_end(n: i32, x: i32) -> i64 {
        return unsafe { (x as u64 | _pdep_u64(n as u64 - 1u64, !(x as u64))) as i64 };
    }
}