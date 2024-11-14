var hasPathSum = function(root, targetSum) {
    if (root == null) {
        return false;
    }

    //minus value of current node
    targetSum -= root.val;
    
    //check if now a leaf node
    if (root.left == null && root.right == null) {
        return targetSum == 0;
    }

    return hasPathSum(root.left, targetSum) || hasPathSum(root.right, targetSum);
};