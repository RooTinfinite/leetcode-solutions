class Solution {
    var result = 0

    func longestConsecutive(_ root: TreeNode?) -> Int {
        func traverse(_ root: TreeNode?, _ curLen: Int, _ parentVal: Int) {
            guard let root = root else {
                return
            }
            var curLen = curLen
            if root.val - parentVal == 1 {
                curLen += 1
            } else {
                curLen = 1
            }

            result = max(curLen, result)
            traverse(root.left, curLen, root.val)
            traverse(root.right,curLen, root.val)
        }
        guard let root = root else { return 0 }
        traverse(root, 1, root.val)
        return result
    }
}