class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> resAverages = new ArrayList<>();
        if (root == null) return resAverages;
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            double sum = 0;
            for (int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();
                sum += node.val;
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
            double avg = sum / levelSize;
            resAverages.add(avg);
        }
        return resAverages;
    }
}