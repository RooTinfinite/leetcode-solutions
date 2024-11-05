class Node {
    TreeNode tn;
    int currentMax = Integer.MIN_VALUE;
    public Node(TreeNode n, int mx) {
        tn = n;
        currentMax = Math.max(mx, n.val);
    }
}
class Solution {
    public int goodNodes(TreeNode root) {
        Deque<Node> stk = new ArrayDeque<>();
        stk.push(new Node(root, root.val));
        int cnt = 0;
        while (!stk.isEmpty()) {
            Node cur = stk.pop();
            cnt += cur.tn.val >= cur.currentMax ? 1 : 0;
            for (TreeNode kid : new TreeNode[]{cur.tn.left, cur.tn.right}) {
                if (kid != null) {
                    stk.push(new Node(kid, cur.currentMax));
                }
            }
        }
        return cnt;
    }
}