/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int levelMedian(TreeNode root, int level) {
        if(level == 0) return root.val;
        Deque<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);

        for(int i = 0; i < level; i++) { //perform one pass of the BFS for each level until we reach the target level
            int len = queue.size();

            for(int l = 0; l < len; l++) { //traverse current level from left to right
                TreeNode current = queue.poll();
                if(current.left != null) queue.add(current.left);
                if(current.right != null) queue.add(current.right);
            }

            if(queue.isEmpty()) return -1; //return early if the next level has no nodes
        }

        int len = queue.size() / 2;
        for(int i = 0; i < len; i++) queue.poll(); //remove the first half of the current level

        return queue.peek().val; //return the current(middle) value
    }
}