class Solution {
private:
    // Return whether or not the tree at root is balanced while also storing
    // the tree's height in a reference variable.
    bool isBalancedTreeHelper(TreeNode* root, int& height) {
        // An empty tree is balanced and has height = -1
        if (root == NULL) {
            height = -1;
            return true;
        }

        // Check subtrees to see if they are balanced. If they are, check if the
        // current node is also balanced using the heights obtained from the
        // recursive calls.
        int left, right;
        if (isBalancedTreeHelper(root->left, left) &&
            isBalancedTreeHelper(root->right, right) && abs(left - right) < 2) {
            // Store the current tree's height
            height = max(left, right) + 1;
            return true;
        }
        return false;
    }

public:
    bool isBalanced(TreeNode* root) {
        int height;
        return isBalancedTreeHelper(root, height);
    }
};