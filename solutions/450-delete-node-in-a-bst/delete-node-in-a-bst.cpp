class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left && !root->right) return nullptr;
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            root->val = findMin(root->right);
            root->right = deleteNode(root->right, root->val);
        }

        return root;
    }

private:
    int findMin(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root->val;
    }
};