class Solution {
public:
    void solve(int value,TreeNode * root, bool &ans){
        if(root==NULL){
            return;
        }
        if(root->val!=value){
           ans=false;
           return;
        }
         solve(value,root->left,ans);
         solve(value,root->right,ans);

    }
    bool isUnivalTree(TreeNode* root) {
        bool ans=true;
        solve(root->val,root,ans);
        return ans;
    }
};