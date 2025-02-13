// Define the Solution class
class Solution {
  
  // Define the isCompleteTree function that takes a TreeNode as input and returns a boolean
  public boolean isCompleteTree(TreeNode root) {
    // Check if the root node is null, if so, return true (an empty tree is complete)
    if (root == null)
      return true;

    // Create a queue to store the nodes of the tree in level order
    Queue<TreeNode> q = new LinkedList<>(Arrays.asList(root));

    // Traverse the tree in level order
    while (q.peek() != null) {
      // Remove the first node from the queue
      TreeNode node = q.poll();
      // Add the left and right child nodes of the current node to the queue
      q.offer(node.left);
      q.offer(node.right);
    }

    // Remove any remaining null nodes from the end of the queue
    while (!q.isEmpty() && q.peek() == null)
      q.poll();

    // Check if there are any remaining nodes in the queue
    // If so, the tree is not complete, so return false
    // Otherwise, the tree is complete, so return true
    return q.isEmpty();
  }
}