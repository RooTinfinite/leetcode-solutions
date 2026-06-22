class Solution {
    public NodeCopy copyRandomBinaryTree(Node root) {
        Map<Node, NodeCopy> map = new HashMap<>();
        return doClone(root, map);
    }
    
    private NodeCopy doClone(Node root, Map<Node, NodeCopy> map) {
        if (root == null) {
            return null;
        }
        if (map.containsKey(root)) {
            return map.get(root);
        } else {
            NodeCopy cur = new NodeCopy(root.val);
            map.put(root, cur);
            cur.left = doClone(root.left, map);
            cur.right = doClone(root.right, map);
            cur.random = doClone(root.random, map);
            return cur;
        }
    }
}