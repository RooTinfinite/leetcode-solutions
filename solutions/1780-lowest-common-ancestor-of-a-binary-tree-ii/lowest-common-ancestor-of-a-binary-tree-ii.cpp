class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool nodesFound = false;

        function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* node) {
            // Base case: If the node is null, return null
            if (!node) return node;

            // Recursively search the left and right subtrees
            TreeNode* left = dfs(node->left);
            TreeNode* right = dfs(node->right);

            // Check conditions for current node being part of the solution
            int conditions = 0;
            if (node == p || node == q) conditions++;
            if (left != NULL) conditions++;
            if (right != NULL) conditions++;
            if (conditions == 2)
                nodesFound = true;  // Mark that both nodes are found

            // Determine if current node is the lowest common ancestor
            if ((left && right) || (node == p) || (node == q)) return node;

            // Return the non-null child, if any
            return left ? left : right;
        };

        // Start DFS traversal to find the lowest common ancestor
        TreeNode* ans = dfs(root);
        // Return the result only if both nodes are found
        return nodesFound ? ans : NULL;
    }
};