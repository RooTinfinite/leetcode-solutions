
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int index = 0;
        traverse(root, voyage, index);
        if (!valid_) {
            return {-1};
        }
        return ret_;
    }

private:
    void traverse(TreeNode* node, vector<int>&voyage, int& index) {
        if (!node) {
            return;
        }
        if (valid_ == false) {
            return;
        }
        if (node->val != voyage[index++]) {
            valid_ = false;
            return;
        }
        if (node->left) {
            if (node->left->val != voyage[index]) {
                std::swap(node->left, node->right);
                ret_.push_back(node->val);
            }
        }
        traverse(node->left, voyage, index);
        traverse(node->right, voyage, index);
    }

    bool valid_ = true;
    std::vector<int> ret_;
};