class Solution {
public:
    int mx = INT_MIN;
    void solve(TreeNode* root, int len, int last)
    {
        if(root==NULL)
        {
            mx = max(mx,len);
            return;
        }
        mx = max(len,mx);
        if(root->val==last+1 || last==INT_MIN)
        {
            solve(root->left,len+1,root->val);
            solve(root->right,len+1,root->val);
        }
        else
        {
            solve(root->left,1,root->val);
            solve(root->right,1,root->val);
        }
    }
    int longestConsecutive(TreeNode* root) 
    {
        solve(root,0,INT_MIN);
        return mx;    
    }
};