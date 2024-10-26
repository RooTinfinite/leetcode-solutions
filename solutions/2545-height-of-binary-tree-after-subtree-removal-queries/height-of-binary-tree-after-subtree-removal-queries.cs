public class Solution {
    // Array to store heights of leaf nodes
    private int[] heights;
    
    // Array to store depth of each node
    private int[] d;
    
    // Arrays to store left and right boundaries of subtrees in the leaf array
    private int[] l;
    private int[] r;
    
    // Counter for number of leaf nodes
    private int lenLeaves;
    
    public int[] TreeQueries(TreeNode root, int[] queries) {
        // Initialize arrays with sufficient size
        // heights stores leaf node heights
        heights = new int[50000];
        // d stores depth of each node (indexed by node value)
        d = new int[100001];
        // l,r store left and right boundaries of subtrees in leaf array
        l = new int[100001];
        r = new int[100001];
        lenLeaves = 0;
        
        // DFS to process the tree and fill arrays
        Search(root, 0);
        
        int n = lenLeaves;
        // Arrays to store maximum heights from left and right
        int[] maxl = new int[n];
        int[] maxr = new int[n];
        
        // Build prefix and suffix maximum arrays
        // maxl[i] stores maximum height from 0 to i-1
        // maxr[i] stores maximum height from i+1 to n-1
        for (int i = 1; i < n; i++) {
            maxl[i] = Math.Max(maxl[i-1], heights[i-1]);
            maxr[n-i-1] = Math.Max(maxr[n-i], heights[n-i]);
        }
        
        var ret = new List<int>();
        
        // Process each query
        foreach (int query in queries) {
            // Get maximum height to the left of current node's subtree
            int maxxl = maxl[l[query]];
            // Get maximum height to the right of current node's subtree
            int maxxr = maxr[r[query]];
            // Result is max of:
            // 1. Maximum height to the left of subtree
            // 2. Maximum height to the right of subtree
            // 3. Depth of current node - 1 (parent's depth)
            ret.Add(Math.Max(Math.Max(maxxl, maxxr), d[query]-1));
        }
        
        return ret.ToArray();
    }
    
    private void Search(TreeNode p, int h) {
        // Store current node's depth
        d[p.val] = h;
        
        // If leaf node, store its height and boundaries
        if (p.left == null && p.right == null) {
            heights[lenLeaves] = h;
            // For leaf nodes, left and right boundaries are same
            l[p.val] = r[p.val] = lenLeaves;
            lenLeaves++;
            return;
        }
        
        // Store left boundary of current subtree
        l[p.val] = lenLeaves;
        
        // Recursively process left and right children
        if (p.left != null) {
            Search(p.left, h + 1);
        }
        if (p.right != null) {
            Search(p.right, h + 1);
        }
        
        // Store right boundary of current subtree
        r[p.val] = lenLeaves - 1;
    }
}