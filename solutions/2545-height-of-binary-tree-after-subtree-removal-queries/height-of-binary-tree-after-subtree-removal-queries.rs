use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn tree_queries(root: Option<Rc<RefCell<TreeNode>>>, queries: Vec<i32>) -> Vec<i32> {
        // Initialize storage vectors
        let mut heights = vec![0; 50000];  // Stores heights of leaf nodes
        let mut len = 0;                   // Tracks number of leaf nodes
        let mut d = vec![0; 100001];       // Stores depth of each node
        let mut l = vec![0; 100001];       // Stores left boundary index for each node
        let mut r = vec![0; 100001];       // Stores right boundary index for each node

        // Depth-First Search implementation
        fn search(
            node: Option<Rc<RefCell<TreeNode>>>,
            h: i32,                        // Current height in tree
            heights: &mut Vec<i32>,        // Mutable reference to heights vector
            len: &mut usize,               // Mutable reference to length counter
            d: &mut Vec<i32>,              // Mutable reference to depths vector
            l: &mut Vec<i32>,              // Mutable reference to left boundaries
            r: &mut Vec<i32>,              // Mutable reference to right boundaries
        ) {
            if let Some(n) = node {
                let node = n.borrow();
                let val = node.val as usize;
                d[val] = h;                // Record current node's depth

                // Handle leaf node case
                if node.left.is_none() && node.right.is_none() {
                    heights[*len] = h;      // Store leaf height
                    l[val] = *len as i32;   // Set left boundary
                    r[val] = *len as i32;   // Set right boundary
                    *len += 1;              // Increment leaf counter
                    return;
                }

                l[val] = *len as i32;      // Set left boundary for internal node

                // Recursively process left and right subtrees
                search(node.left.clone(), h + 1, heights, len, d, l, r);
                search(node.right.clone(), h + 1, heights, len, d, l, r);

                r[val] = (*len - 1) as i32; // Set right boundary for internal node
            }
        }

        // Process the tree starting from root
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
        // Arrays to store maximum heights from left and right
        let mut maxl = vec![0; n];
        let mut maxr = vec![0; n];

        // Build prefix (left) and suffix (right) maximum arrays
        for i in 1..n {
            maxl[i] = maxl[i - 1].max(heights[i - 1]);    // Maximum height from left
            maxr[n - i - 1] = maxr[n - i].max(heights[n - i]); // Maximum height from right
        }

        // Process each query and build result vector
        queries
            .iter()
            .map(|&q| {
                let q = q as usize;
                let maxxl = maxl[l[q] as usize];          // Max height to the left
                let maxxr = maxr[r[q] as usize];          // Max height to the right
                maxxl.max(maxxr).max(d[q] - 1)            // Take maximum of left, right, and depth-1
            })
            .collect()                                     // Collect results into vector
    }
}