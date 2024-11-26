
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
          if (nums.empty()) return NULL;
        auto m = max_element(begin(nums), end(nums));
        TreeNode* root = new TreeNode(*m);
        if (m != begin(nums)) {
            vector<int> left(begin(nums), m);
            root->left = constructMaximumBinaryTree(left);
        }
        if (m != end(nums) - 1) {
            vector<int> right(m + 1, end(nums));
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
};
    