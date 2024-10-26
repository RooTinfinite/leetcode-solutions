class Solution {
    private var maxHeightAfterRemoval = Array(repeating: 0, count: 100001)
    private var currentMaxHeight = 0
    
    func treeQueries(_ root: TreeNode?, _ queries: [Int]) -> [Int] {
        traverseLeftToRight(root, 0)
        currentMaxHeight = 0  // Reset for second traversal
        traverseRightToLeft(root, 0)
        
        // Process queries and build result array
        return queries.map { maxHeightAfterRemoval[$0] }
    }
    
    private func traverseLeftToRight(_ node: TreeNode?, _ currentHeight: Int) {
        guard let node = node else { return }
        
        // Store maximum height if this node were removed
        maxHeightAfterRemoval[node.val] = currentMaxHeight
        
        // Update current maximum height
        currentMaxHeight = max(currentMaxHeight, currentHeight)
        
        // Traverse left subtree first, then right
        traverseLeftToRight(node.left, currentHeight + 1)
        traverseLeftToRight(node.right, currentHeight + 1)
    }
    
    private func traverseRightToLeft(_ node: TreeNode?, _ currentHeight: Int) {
        guard let node = node else { return }
        
        // Update maximum height if this node were removed
        maxHeightAfterRemoval[node.val] = max(
            maxHeightAfterRemoval[node.val],
            currentMaxHeight
        )
        
        // Update current maximum height
        currentMaxHeight = max(currentHeight, currentMaxHeight)
        
        // Traverse right subtree first, then left
        traverseRightToLeft(node.right, currentHeight + 1)
        traverseRightToLeft(node.left, currentHeight + 1)
    }
}