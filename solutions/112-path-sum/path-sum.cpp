class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        std::stack<TreeNode*> node_stack;
        std::stack<int> sum_stack;
        node_stack.push(root);
        sum_stack.push(sum - root->val);
        TreeNode* node;
        int curr_sum;
        while (!node_stack.empty()) {
            node = node_stack.top();
            node_stack.pop();
            curr_sum = sum_stack.top();
            sum_stack.pop();
            if ((node->right == NULL) && (node->left == NULL) &&
                (curr_sum == 0))
                return true;
            if (node->right != NULL) {
                node_stack.push(node->right);
                sum_stack.push(curr_sum - node->right->val);
            }
            if (node->left != NULL) {
                node_stack.push(node->left);
                sum_stack.push(curr_sum - node->left->val);
            }
        }
        return false;
    }
};