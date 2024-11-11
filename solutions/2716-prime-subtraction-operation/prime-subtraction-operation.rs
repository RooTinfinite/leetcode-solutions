impl Solution {
    pub fn prime_sub_operation(nums: Vec<i32>) -> bool {
        let max_element = Self::get_max_element(&nums);
        
        // Create Sieve of Eratosthenes array to identify prime numbers
        let mut sieve = vec![true; (max_element + 1) as usize];
        sieve[1] = false;
        
        let sqrt = (((max_element + 1) as f64).sqrt()) as i32;
        for i in 2..=sqrt {
            if sieve[i as usize] {
                let mut j = i * i;
                while j <= max_element {
                    sieve[j as usize] = false;
                    j += i;
                }
            }
        }

        // Check if array can be made strictly increasing by subtracting prime numbers
        let mut curr_value = 1;
        let mut i = 0;
        
        while i < nums.len() {
            let difference = nums[i] - curr_value;

            // Return false if current number is already smaller than required value
            if difference < 0 {
                return false;
            }

            // Move to next number if difference is prime or zero
            if difference == 0 || sieve[difference as usize] {
                i += 1;
                curr_value += 1;
            } else {
                curr_value += 1;
            }
        }
        true
    }

    // Helper method to find maximum element in array
    fn get_max_element(nums: &[i32]) -> i32 {
        *nums.iter().max().unwrap_or(&-1)
    }
}
