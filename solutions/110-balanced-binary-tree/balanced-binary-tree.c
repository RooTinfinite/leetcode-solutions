typedef struct {
    int height;
    bool balanced;
} TreeInfo;
// Returns whether the tree at root is balanced, along with the tree's height.
TreeInfo isBalancedTreeHelper(struct TreeNode* root) {
    TreeInfo info;
    // An empty tree is both balanced and has a height -1.
    if (root == NULL) {
        info.height = -1;
        info.balanced = true;
        return info;
    }
    TreeInfo left = isBalancedTreeHelper(root->left);
    if (!left.balanced) {
        info.height = -1;
        info.balanced = false;
        return info;
    }
    TreeInfo right = isBalancedTreeHelper(root->right);
    if (!right.balanced) {
        info.height = -1;
        info.balanced = false;
        return info;
    }
    // The obtained height from recursive calls can also determine
    // that the current node is balanced.
    if (abs(left.height - right.height) < 2) {
        info.height =
            (left.height > right.height ? left.height : right.height) + 1;
        info.balanced = true;
        return info;
    }
    info.height = -1;
    info.balanced = false;
    return info;
}
bool isBalanced(struct TreeNode* root) {
    return isBalancedTreeHelper(root).balanced;
}