class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;

        long long firstMin = root->val;
        long long secondMin = LONG_MAX;

        TreeNode* current = root;

        while (current) {
            if (!current->left) {
                // Process current node as there is no left subtree
                if (current->val > firstMin && current->val < secondMin) {
                    secondMin = current->val;
                }
                current = current->right;
            } else {
                // Find the predecessor of current
                TreeNode* predecessor = current->left;
                while (predecessor->right && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if (!predecessor->right) {
                    // Create a temporary link to current
                    predecessor->right = current;
                    current = current->left;
                } else {
                    // Restore the tree and process current node
                    predecessor->right = nullptr;
                    if (current->val > firstMin && current->val < secondMin) {
                        secondMin = current->val;
                    }
                    current = current->right;
                }
            }
        }

        return secondMin == LONG_MAX ? -1 : secondMin;
    }
};