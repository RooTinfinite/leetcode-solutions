impl Solution {
    pub fn min_end(n: i32, x: i32) -> i64 {
        #[cfg(target_arch = "x86_64")]
        unsafe {
            (x as u64 | core::arch::x86_64::_pdep_u64(n as u64 - 1, !(x as u64))) as i64
        }
    }
}