var deleteNode = function (root, key) {

    function removeNode(root, key) {

        if (root == null) return null;
        if (key < root.val) {
            root.left = removeNode(root.left, key);
        }

        else if (key > root.val) {
            root.right = removeNode(root.right, key);
        } 
        else {
            if (!root.left && !root.right) return null;
            if (!root.left) return root.right;
            if (!root.right) return root.left;
            root.val = min(root.right);
            root.right = removeNode(root.right, root.val);
        }

        return root;
    }
    return removeNode(root, key)
};

function min(root) {
    if (!root.left) return root.val;
    return min(root.left);
}