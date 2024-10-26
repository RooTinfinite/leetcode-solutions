type Solution struct {
    maxHeightAfterRemoval [100001]int
    currentMaxHeight      int
}

func treeQueries(root *TreeNode, queries []int) []int {
    sol := &Solution{}
    
    // First traversal from left to right
    sol.traverseLeftToRight(root, 0)
    
    // Reset current max height for second traversal
    sol.currentMaxHeight = 0
    sol.traverseRightToLeft(root, 0)
    
    // Process queries and build result
    queryResults := make([]int, len(queries))
    for i, query := range queries {
        queryResults[i] = sol.maxHeightAfterRemoval[query]
    }
    
    return queryResults
}

func (s *Solution) traverseLeftToRight(node *TreeNode, currentHeight int) {
    if node == nil {
        return
    }
    
    // Store the maximum height if this node were removed
    s.maxHeightAfterRemoval[node.Val] = s.currentMaxHeight
    
    // Update current maximum height
    s.currentMaxHeight = max(s.currentMaxHeight, currentHeight)
    
    // Traverse left subtree first, then right
    s.traverseLeftToRight(node.Left, currentHeight + 1)
    s.traverseLeftToRight(node.Right, currentHeight + 1)
}

func (s *Solution) traverseRightToLeft(node *TreeNode, currentHeight int) {
    if node == nil {
        return
    }
    
    // Update maximum height if this node were removed
    s.maxHeightAfterRemoval[node.Val] = max(
        s.maxHeightAfterRemoval[node.Val],
        s.currentMaxHeight,
    )
    
    // Update current maximum height
    s.currentMaxHeight = max(currentHeight, s.currentMaxHeight)
    
    // Traverse right subtree first, then left
    s.traverseRightToLeft(node.Right, currentHeight + 1)
    s.traverseRightToLeft(node.Left, currentHeight + 1)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}