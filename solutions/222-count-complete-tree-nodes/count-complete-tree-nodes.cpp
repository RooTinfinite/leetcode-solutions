/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int helper(TreeNode* root, int count) {
        if (root == NULL)
            return count;
        count = helper(root->left, count + 1);
        count = helper(root->right, count);
        return count;
    }

public:
    int countNodes(TreeNode* root) { 
        return helper(root, 0);
        }
};