class Solution {
public:
    int tiltSum = 0;
    int findTilt(TreeNode* root) {
        DFS(root);
        return tiltSum;
    }
    int DFS(TreeNode* root) {
        if(!root) return 0;
        int leftSum = DFS(root -> left);                // sum of left subtree
        int rightSum = DFS(root -> right);              // sum of right subtree
        tiltSum += abs(leftSum - rightSum);             // add tilt of current node to overall tiltSum
        return leftSum + rightSum + root -> val;        // returns sum of subtree starting at 'root'
    }
};