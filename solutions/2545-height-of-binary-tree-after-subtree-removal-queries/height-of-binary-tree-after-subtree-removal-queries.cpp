class Solution {
public:
    // Arrays to store heights of leaf nodes and other node information
    int heights[50000],len=0;  // heights stores leaf node heights, len tracks number of leaves
    int d[100001],l[100001],r[100001];  // d:depth, l:left index, r:right index for each node

    // DFS traversal to process the tree
    void search(TreeNode *p,int h){
        int left,right;
        d[p->val] = h;  // Store current node's depth

        // If leaf node found
        if (!p->left && !p->right){
            heights[len] = h;    // Store leaf height
            l[p->val] = r[p->val] = len;  // Both left and right indices same for leaf
            len++;  // Increment leaf counter
            return;
        }

        l[p->val] = len;  // Store left index for current node
        
        // Recursively process left and right subtrees
        if (p->left) search(p->left,h+1);
        if (p->right) search(p->right,h+1);
        
        r[p->val] = len-1;  // Store right index for current node
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Optimization for I/O operations
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        search(root,0);  // Process the tree starting from root
        
        int n = len;  // Total number of leaf nodes
        int maxl[n],maxr[n];  // Arrays to store max heights from left and right
        maxl[0] = maxr[n-1] = 0;  // Initialize boundaries
        
        // Build prefix and suffix maximum arrays
        for (int i=1;i<n;i++){
            maxl[i] = max(maxl[i-1],heights[i-1]);  // Max height from left
            maxr[n-i-1] = max(maxr[n-i],heights[n-i]);  // Max height from right
        }

        vector<int> ret;  // Result vector
        int k = queries.size();
        
        // Process each query
        for (int i=0;i<k;i++){
            // Find maximum height excluding current node's subtree
            int maxxl = maxl[l[queries[i]]];  // Max height to the left
            int maxxr = maxr[r[queries[i]]];  // Max height to the right
            // Result is max of (max left height, max right height, current depth-1)
            ret.push_back(max(max(maxxl,maxxr),d[queries[i]]-1));
        }
        
        return ret;
    }
};