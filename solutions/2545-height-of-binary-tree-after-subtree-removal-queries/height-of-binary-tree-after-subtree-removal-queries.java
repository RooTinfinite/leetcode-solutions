class Solution {
    // Arrays to store information about the tree
    private int[] heights;  // Stores heights of leaf nodes in order of traversal
    private int[] d;        // Stores depth/height of each node by its value
    private int[] l;        // Stores left boundary index for each node value
    private int[] r;        // Stores right boundary index for each node value
    private int lenLeaves;  // Counts number of leaf nodes encountered
    
    public int[] treeQueries(TreeNode root, int[] queries) {
        // Initialize arrays with sufficient size
        heights = new int[50000];    // For storing leaf heights
        d = new int[100001];         // For storing node depths
        l = new int[100001];         // For storing left boundaries
        r = new int[100001];         // For storing right boundaries
        lenLeaves = 0;               // Initialize leaf counter
        
        // DFS to process the tree and fill arrays
        search(root, 0);
        
        int n = lenLeaves;
        // Arrays to store maximum heights from left and right
        int[] maxl = new int[n];     // Prefix maximums
        int[] maxr = new int[n];     // Suffix maximums
        
        // Build prefix maximum array (left to right)
        // At each position i, stores max height of all leaves to the left
        for (int i = 1; i < n; i++) {
            maxl[i] = Math.max(maxl[i-1], heights[i-1]);
        }
        
        // Build suffix maximum array (right to left)
        // At each position i, stores max height of all leaves to the right
        for (int i = n-2; i >= 0; i--) {
            maxr[i] = Math.max(maxr[i+1], heights[i+1]);
        }
        
        // Process each query
        int[] ret = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int query = queries[i];
            // Find maximum height outside the range of current node
            int maxxl = maxl[l[query]];          // Max height to the left
            int maxxr = maxr[r[query]];          // Max height to the right
            // Result is maximum of left max, right max, and parent height
            ret[i] = Math.max(Math.max(maxxl, maxxr), d[query]-1);
        }
        
        return ret;
    }
    
    // DFS to process the tree
    private void search(TreeNode p, int h) {
        d[p.val] = h;    // Store current node's height
        
        // If current node is a leaf
        if (p.left == null && p.right == null) {
            heights[lenLeaves] = h;   // Store leaf height
            l[p.val] = r[p.val] = lenLeaves;  // Both boundaries point to same index
            lenLeaves++;              // Increment leaf counter
            return;
        }
        
        l[p.val] = lenLeaves;        // Store left boundary
        
        // Recursively process left and right subtrees
        if (p.left != null) {
            search(p.left, h + 1);
        }
        if (p.right != null) {
            search(p.right, h + 1);
        }
        
        r[p.val] = lenLeaves - 1;    // Store right boundary
    }
}