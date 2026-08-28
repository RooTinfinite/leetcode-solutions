class BSTIterator {
public:
    stack<TreeNode*> stack;

    BSTIterator(TreeNode* root) {
        // Stack for the recursion simulation
        this->_leftmostInorder(root);
    }

    void _leftmostInorder(TreeNode* root) {
        // For a given node, add all the elements in the leftmost branch of the
        // tree under it to the stack.
        while (root != NULL) {
            this->stack.push(root);
            root = root->left;
        }
    }

    /**
     * @return the next smallest number
     */
    int next() {
        // Node at the top of the stack is the next smallest element
        TreeNode* topmostNode = this->stack.top();
        this->stack.pop();

        // Need to maintain the invariant. If the node has a right child, call
        // the helper function for the right child
        if (topmostNode->right != NULL) {
            this->_leftmostInorder(topmostNode->right);
        }

        return topmostNode->val;
    }

    /**
     * @return whether we have a next smallest number
     */
    bool hasNext() { return !this->stack.empty(); }
};