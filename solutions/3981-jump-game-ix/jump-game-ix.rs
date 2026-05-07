impl Solution {
    pub fn max_value(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();

        let mut ans = vec![0; n];

        struct Item {
            value: i32,
            left: usize,
            right: usize,
        }

        let mut stack: Vec<Item> = Vec::new();

        for i in 0..n {
            let mut curr = Item {
                value: nums[i],
                left: i,
                right: i,
            };

            while let Some(top) = stack.last() {
                if top.value > nums[i] {
                    let top = stack.pop().unwrap();
                    curr.value = curr.value.max(top.value);
                    curr.left = top.left;
                } else {
                    break;
                }
            }

            stack.push(curr);
        }

        for i in 0..stack.len() {
            for j in stack[i].left..=stack[i].right {
                ans[j] = stack[i].value;
            }
        }

        ans
    }
}