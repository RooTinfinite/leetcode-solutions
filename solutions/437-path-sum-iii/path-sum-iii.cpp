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
public:

    unordered_map<long long,int>mp;
    int ans = 0;
    void f(TreeNode * root , long long sum , long long target){
        if(root == nullptr)return ;

        sum += root->val;
        if(mp.find( -target +sum) != mp.end()){
            ans+= mp[sum-target];
        }
        mp[sum]++;

        f(root->left,sum,target);
        f(root->right,sum,target);

        mp[sum]--;
        if(mp[sum] == 0)mp.erase(sum);

        sum-=root->val;

    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;

        f(root,0,targetSum);
        return ans;
    }
};