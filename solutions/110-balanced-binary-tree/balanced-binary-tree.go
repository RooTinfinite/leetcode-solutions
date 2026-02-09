// Compute the tree's height via recursion
func height(root *TreeNode) int {
    // An empty tree has height -1
    if root == nil {
        return -1
    }
    return 1 + max(height(root.Left), height(root.Right))
}

func isBalanced(root *TreeNode) bool {
    // An empty tree satisfies the definition of a balanced tree
    if root == nil {
        return true
    }
    // Check if subtrees have height within 1. If they do, check if the subtrees are balanced
    return abs(height(root.Left)-height(root.Right)) < 2 &&
        isBalanced(root.Left) &&
        isBalanced(root.Right)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}