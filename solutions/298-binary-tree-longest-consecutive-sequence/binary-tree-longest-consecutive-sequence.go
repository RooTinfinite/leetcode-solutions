func longestConsecutive(root *TreeNode) int {
    return dfs(root, root.Val, 0)
}

func dfs(node *TreeNode, pValue, count int) int {
    if node == nil {
        return count
    }

    if node.Val == pValue+1 {
        count++
    } else {
        count = 1
    }

    return max(count, max(dfs(node.Left, node.Val, count), dfs(node.Right, node.Val, count)))
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}