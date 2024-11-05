class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        
        TreeNode* resL = lowestCommonAncestor(root->left, p, q);
        TreeNode* resR = lowestCommonAncestor(root->right, p, q);
        
        if (resL && resR) {
            return root;
        } else if (resL) {
            return resL;
        } else {
            return resR;
        }
    }
};