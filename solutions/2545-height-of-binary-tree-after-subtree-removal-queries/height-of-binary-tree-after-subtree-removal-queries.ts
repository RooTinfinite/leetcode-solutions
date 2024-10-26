// Function that processes queries about maximum heights in a binary tree excluding specific nodes
function treeQueries(root: TreeNode | null, queries: number[]): number[] {
    // Arrays to store various tree-related information
    const heights: number[] = new Array(50000).fill(0);  // Stores heights of leaf nodes
    const d: number[] = new Array(100001).fill(0);       // Stores depth of each node
    const l: number[] = new Array(100001).fill(0);       // Stores left boundary index for each node
    const r: number[] = new Array(100001).fill(0);       // Stores right boundary index for each node
    let len: number = 0;                                 // Counter for leaf nodes
    
    // DFS function to process the tree
    function search(p: TreeNode, h: number): void {
        // Store current node's depth
        d[p.val] = h;
        
        // If current node is a leaf node
        if (!p.left && !p.right) {
            heights[len] = h;           // Store its height
            l[p.val] = r[p.val] = len;  // Set left and right boundaries to current index
            len++;                      // Increment leaf counter
            return;
        }
        
        // Store left boundary for current node
        l[p.val] = len;
        
        // Recursively process left and right subtrees
        if (p.left) search(p.left, h + 1);
        if (p.right) search(p.right, h + 1);
        
        // Store right boundary for current node
        r[p.val] = len - 1;
    }
    
    // Handle empty tree case
    if (!root) return [];
    search(root, 0);
    
    const n: number = len;
    // Arrays to store maximum heights from left and right
    const maxl: number[] = new Array(n).fill(0);
    const maxr: number[] = new Array(n).fill(0);
    
    // Compute maximum heights from left to right and right to left
    for (let i = 1; i < n; i++) {
        maxl[i] = Math.max(maxl[i-1], heights[i-1]);     // Left to right maximums
        maxr[n-i-1] = Math.max(maxr[n-i], heights[n-i]); // Right to left maximums
    }
    
    // Process queries
    const ret: number[] = [];
    const k: number = queries.length;
    
    for (let i = 0; i < k; i++) {
        // For each query, find maximum height possible when removing the queried node
        const maxxl: number = maxl[l[queries[i]]];        // Max height to the left
        const maxxr: number = maxr[r[queries[i]]];        // Max height to the right
        // Result is maximum of:
        // 1. Maximum height to the left of node
        // 2. Maximum height to the right of node
        // 3. Node's depth minus 1 (representing parent's path)
        ret.push(Math.max(Math.max(maxxl, maxxr), d[queries[i]] - 1));
    }
    
    return ret;
}

