// Function to process tree queries that finds max height excluding certain nodes
var treeQueries = function(root, queries) {
    // Array to store heights of leaf nodes
    const heights = new Array(50000).fill(0);
    
    // Array to store depth of each node (indexed by node value)
    const d = new Array(100001).fill(0);
    
    // Arrays to store left and right boundaries for each node's subtree
    const l = new Array(100001).fill(0);
    const r = new Array(100001).fill(0);
    
    // Counter for number of leaf nodes
    let len = 0;
    
    // DFS function to process the tree
    function search(p, h) {
        // Store current node's depth
        d[p.val] = h;
        
        // If current node is a leaf node
        if (!p.left && !p.right) {
            heights[len] = h;  // Store its height
            l[p.val] = r[p.val] = len;  // Set left and right boundaries
            len++;  // Increment leaf counter
            return;
        }
        
        // Store left boundary for current node
        l[p.val] = len;
        
        // Recursively process left and right children
        if (p.left) search(p.left, h + 1);
        if (p.right) search(p.right, h + 1);
        
        // Store right boundary for current node
        r[p.val] = len - 1;
    }
    
    // Start DFS from root
    search(root, 0);
    
    const n = len;
    // Arrays to store maximum heights from left and right
    const maxl = new Array(n).fill(0);
    const maxr = new Array(n).fill(0);
    
    // Build prefix and suffix maximum arrays
    for (let i = 1; i < n; i++) {
        maxl[i] = Math.max(maxl[i-1], heights[i-1]);  // Left to right max
        maxr[n-i-1] = Math.max(maxr[n-i], heights[n-i]);  // Right to left max
    }
    
    // Array to store results
    const ret = [];
    const k = queries.length;
    
    // Process each query
    for (let i = 0; i < k; i++) {
        // Find maximum height excluding current node's subtree
        const maxxl = maxl[l[queries[i]]];  // Max height to the left
        const maxxr = maxr[r[queries[i]]];  // Max height to the right
        // Result is max of left max, right max, and node's depth-1
        ret.push(Math.max(Math.max(maxxl, maxxr), d[queries[i]] - 1));
    }
    
    return ret;
};