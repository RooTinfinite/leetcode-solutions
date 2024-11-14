class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        res_averages = []
        if not root:
            return res_averages

        queue = deque([root])

        while queue:
            level_size = len(queue)
            level_sum = 0
            for _ in range(level_size):
                node = queue.popleft()
                level_sum += node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            avg = level_sum / level_size
            res_averages.append(avg)

        return res_averages