use std::cell::RefCell;
use std::cmp::Reverse;
use std::collections::BinaryHeap;
use std::rc::Rc;

struct StabilityCost {
    left: BinaryHeap<i64>,
    right: BinaryHeap<Reverse<i64>>,
    left_offset: i64,
    right_offset: i64,
    minimum: i64,
}

impl StabilityCost {
    fn new() -> Self {
        Self {
            left: BinaryHeap::new(),
            right: BinaryHeap::new(),
            left_offset: 0,
            right_offset: 0,
            minimum: 0,
        }
    }

    fn add_left_hinge(&mut self, value: i64) {
        if let Some(&Reverse(raw)) = self.right.peek() {
            let boundary = raw + self.right_offset;
            if value > boundary {
                self.minimum += value - boundary;
                self.right.pop();
                self.right.push(Reverse(value - self.right_offset));
                self.left.push(boundary - self.left_offset);
                return;
            }
        }
        self.left.push(value - self.left_offset);
    }

    fn add_right_hinge(&mut self, value: i64) {
        if let Some(&raw) = self.left.peek() {
            let boundary = raw + self.left_offset;
            if value < boundary {
                self.minimum += boundary - value;
                self.left.pop();
                self.left.push(value - self.left_offset);
                self.right.push(Reverse(boundary - self.right_offset));
                return;
            }
        }
        self.right.push(Reverse(value - self.right_offset));
    }

    fn expand(&mut self) {
        self.left_offset -= 1;
        self.right_offset += 1;
    }

    fn merge(&mut self, other: Self) {
        self.minimum += other.minimum;
        for raw in other.left {
            self.add_left_hinge(raw + other.left_offset);
        }
        for Reverse(raw) in other.right {
            self.add_right_hinge(raw + other.right_offset);
        }
    }
}

enum StabilityTask {
    Visit(Rc<RefCell<TreeNode>>),
    Finish(i64, usize),
}

impl Solution {
    pub fn stabilize_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i64 {
        let Some(root) = root else {
            return 0;
        };

        let mut tasks = vec![StabilityTask::Visit(root)];
        let mut results: Vec<StabilityCost> = Vec::new();

        while let Some(task) = tasks.pop() {
            match task {
                StabilityTask::Visit(node) => {
                    let (value, left, right) = {
                        let node = node.borrow();
                        (node.val as i64, node.left.clone(), node.right.clone())
                    };

                    let children =
                        usize::from(left.is_some()) + usize::from(right.is_some());
                    tasks.push(StabilityTask::Finish(value, children));

                    if let Some(left) = left {
                        tasks.push(StabilityTask::Visit(left));
                    }
                    if let Some(right) = right {
                        tasks.push(StabilityTask::Visit(right));
                    }
                }
                StabilityTask::Finish(value, children) => {
                    let mut cost = if children == 0 {
                        StabilityCost::new()
                    } else {
                        let mut child = results.pop().unwrap();
                        child.expand();
                        child
                    };

                    if children == 2 {
                        let mut other = results.pop().unwrap();
                        other.expand();
                        if cost.left.len() < other.left.len() {
                            std::mem::swap(&mut cost, &mut other);
                        }
                        cost.merge(other);
                    }

                    cost.add_left_hinge(value);
                    cost.add_right_hinge(value);
                    results.push(cost);
                }
            }
        }

        results.pop().unwrap().minimum
    }
}