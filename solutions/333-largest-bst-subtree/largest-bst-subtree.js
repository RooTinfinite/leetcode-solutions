// Each node will return isBST, max node value, min node value, size
class NodeValue {
    constructor(minNode, maxNode, maxSize) {
        this.maxNode = maxNode;
        this.minNode = minNode;
        this.maxSize = maxSize;
    }
};

let largestBSTSubtreeHelper = root => {
    // An empty tree is a BST of size 0.
        if (!root) {
            return new NodeValue(Number.MAX_SAFE_INTEGER, Number.MIN_SAFE_INTEGER, 0);
        }
        
        // Get values from left and right subtree of current tree.
        let left = largestBSTSubtreeHelper(root.left);
        let right = largestBSTSubtreeHelper(root.right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root.val && root.val < right.minNode) {
            // It is a BST.
            return new NodeValue(Math.min(root.val, left.minNode), Math.max(root.val, right.maxNode), 
                                left.maxSize + right.maxSize + 1);
        }
        
        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return new NodeValue(Number.MIN_SAFE_INTEGER, Number.MAX_SAFE_INTEGER, 
                            Math.max(left.maxSize, right.maxSize));
}
    
let largestBSTSubtree = root => {
    return largestBSTSubtreeHelper(root).maxSize;
};