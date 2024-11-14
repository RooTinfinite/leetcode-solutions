/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int a = countNodes(root->left);
    int b = countNodes(root->right);
    return a + b + 1;
}