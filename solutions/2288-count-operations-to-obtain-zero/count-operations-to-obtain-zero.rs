impl Solution {
    pub fn count_operations(mut num1: i32, mut num2: i32) -> i32 {
        let mut res = 0;   // total number of subtraction operations
        while num1 != 0 && num2 != 0 {
            // each step of the Euclidean algorithm
            res += num1 / num2;
            num1 %= num2;
            // swap two numbers
            std::mem::swap(&mut num1, &mut num2);
        }
        res
    }
}