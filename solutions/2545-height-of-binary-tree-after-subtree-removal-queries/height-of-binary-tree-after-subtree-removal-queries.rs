use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn tree_queries(root: Option<Rc<RefCell<TreeNode>>>, queries: Vec<i32>) -> Vec<i32> {
        let mut heights = vec![0; 50000];
        let mut len = 0;
        let mut d = vec![0; 100001];
        let mut l = vec![0; 100001];
        let mut r = vec![0; 100001];

        // DFS function to process the tree
        fn search(
            node: Option<Rc<RefCell<TreeNode>>>,
            h: i32,
            heights: &mut Vec<i32>,
            len: &mut usize,
            d: &mut Vec<i32>,
            l: &mut Vec<i32>,
            r: &mut Vec<i32>,
        ) {
            if let Some(n) = node {
                let node = n.borrow();
                let val = node.val as usize;
                d[val] = h;

                // Leaf node case
                if node.left.is_none() && node.right.is_none() {
                    heights[*len] = h;
                    l[val] = *len as i32;
                    r[val] = *len as i32;
                    *len += 1;
                    return;
                }

                l[val] = *len as i32;

                search(node.left.clone(), h + 1, heights, len, d, l, r);
                search(node.right.clone(), h + 1, heights, len, d, l, r);

                r[val] = (*len - 1) as i32;
            }
        }

        search(
            root,
            0,
            &mut heights,
            &mut len,
            &mut d,
            &mut l,
            &mut r,
        );

        let n = len;
        let mut maxl = vec![0; n];
        let mut maxr = vec![0; n];

        // Build prefix and suffix maximum arrays
        for i in 1..n {
            maxl[i] = maxl[i - 1].max(heights[i - 1]);
            maxr[n - i - 1] = maxr[n - i].max(heights[n - i]);
        }

        // Process queries
        queries
            .iter()
            .map(|&q| {
                let q = q as usize;
                let maxxl = maxl[l[q] as usize];
                let maxxr = maxr[r[q] as usize];
                maxxl.max(maxxr).max(d[q] - 1)
            })
            .collect()
    }
}