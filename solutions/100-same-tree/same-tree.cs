public class Solution {
    public bool IsSameTree(TreeNode p, TreeNode q) {
        Queue<(TreeNode, TreeNode)> deq = new Queue<(TreeNode, TreeNode)>();
        deq.Enqueue((p, q));
        while (deq.Count != 0) {
            (p, q) = deq.Dequeue();
            if (p == null && q == null)
                continue;
            if (q == null || p == null)
                return false;
            if (p.val != q.val)
                return false;
            deq.Enqueue((p.left, q.left));
            deq.Enqueue((p.right, q.right));
        }

        return true;
    }
}