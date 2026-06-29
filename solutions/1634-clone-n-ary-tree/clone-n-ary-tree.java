class Solution {
    public Node cloneTree(Node root) {
        if (root == null) {
            return root;
        }

        Node newRoot = new Node(root.val);

        // Starting point to kick off the BFS visits.
        // Here we used the ArrayDeque instead of the Queue class,
        //   which is a more efficient implementation of queue data structure.
        Deque<Node[]> queue = new ArrayDeque<>();
        queue.addLast(new Node[]{root, newRoot});

        while (!queue.isEmpty()) {
            Node[] nodePair = queue.removeFirst();

            Node oldNode = nodePair[0];
            Node newNode = nodePair[1];
            for (Node childNode : oldNode.children) {
                Node newChildNode = new Node(childNode.val);

                // Make a copy for each child node.
                newNode.children.add(newChildNode);

                // Schedule a visit to copy the child nodes of each child node.
                queue.addLast(new Node[]{childNode, newChildNode});
            }
        }

        return newRoot;
    }
}