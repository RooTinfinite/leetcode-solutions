class Solution {
    public Node lowestCommonAncestor(Node p, Node q) {
        Set<Node> set = new HashSet<>();
        while(p != null || q != null) {
            if(p != null) {
                if(!set.add(p)) {
                    return p;
                }
                p = p.parent;
            }
            if(q != null) {
                if(!set.add(q)) {
                    return q;
                }
                q = q.parent;
            }
        }
        return null;
    }
}