/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    class Info{
        public:
            int inc_len;
            int dec_len;
            int me;
            Info(int me, int inc_len = 1, int dec_len = 1): me(me), inc_len(inc_len), dec_len(dec_len){}
    };
public:
    Info getLongest(TreeNode* root, int &ans){
        if (root->right == NULL && root->left == NULL){
            return Info(root->val);
        }
        // perform LRV
        Info left(1e9, 0, 0);
        Info right(1e9, 0, 0);
        if(root->left){
            left = getLongest(root->left, ans);
        }
        if(root->right){
            right = getLongest(root->right, ans);
        }
        

        int inc_len_left = 0;
        int dec_len_left = 0;
        if(root->val == left.me + 1) {
            // decreasing down on left
            dec_len_left = left.dec_len;
            ans = max(ans, dec_len_left + 1);
        } else if(root->val == left.me - 1){
            // increasing down on left
            inc_len_left = left.inc_len;
            ans = max(ans, inc_len_left + 1);
        }

        int inc_len_right = 0;
        int dec_len_right = 0;
        if(root->val == right.me + 1) {
            // decreasing down on right
            dec_len_right = right.dec_len;
            ans = max(ans, dec_len_right + 1);
        } else if(root->val == right.me - 1){
            // increasing down on right
            inc_len_right = right.inc_len;
            ans = max(ans, inc_len_right + 1);
        }

        // finally to see if a path is rooted at this 
        ans = max(ans, inc_len_left + dec_len_right + 1);
        ans = max(ans, dec_len_left + inc_len_right + 1);

        return Info(root->val, max(inc_len_left, inc_len_right) + 1, max(dec_len_left, dec_len_right) + 1);

    }
    int longestConsecutive(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        int ans = 1;
        Info _ = getLongest(root, ans);
        return ans;
    }
};