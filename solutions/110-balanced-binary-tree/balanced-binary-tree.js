// Utility class to store information from recursive calls
class TreeInfo {
    constructor(height, balanced) {
        this.height = height;
        this.balanced = balanced;
    }
}
var isBalanced = function (root) {
    // Returns whether the tree at root is balanced, along with the tree's height.
    function isBalancedTreeHelper(root) {
        // An empty tree is balanced and has a height -1.
        if (root == null) {
            return new TreeInfo(-1, true);
        }
        // Checks whether the subtrees are balanced or not.
        const left = isBalancedTreeHelper(root.left);
        if (!left.balanced) {
            return new TreeInfo(-1, false);
        }
        const right = isBalancedTreeHelper(root.right);
        if (!right.balanced) {
            return new TreeInfo(-1, false);
        }
        // The height obtained from the recursive calls is used to determine
        // whether the current node is balanced.
        if (Math.abs(left.height - right.height) < 2) {
            return new TreeInfo(Math.max(left.height, right.height) + 1, true);
        }
        return new TreeInfo(-1, false);
    }
    return isBalancedTreeHelper(root).balanced;
};