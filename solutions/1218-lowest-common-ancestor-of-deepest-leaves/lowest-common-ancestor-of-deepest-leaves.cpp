class Solution {
    TreeNode* ans;
    int leafDepth(TreeNode* root, int d, int &maxD) {
        if(!root) return d - 1;
        int l = leafDepth(root -> left, d + 1, maxD);
        int r = leafDepth(root -> right, d + 1, maxD);
        int leafD = max(l, r);
        maxD = max(maxD, leafD);
        if(maxD == l && l == r) ans = root;
        return leafD;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxD = 0;
        leafDepth(root, 0, maxD);
        return ans;
    }
};