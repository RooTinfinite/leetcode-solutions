class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':
        if not root:
            return None
        newRoot = Node(root.val)
        for child in root.children:
            newRoot.children.append(self.cloneTree(child))
        return newRoot