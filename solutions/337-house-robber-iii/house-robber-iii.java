class Solution {
    public int rob(TreeNode root) {
        if (root == null) {
            return 0;
        }
        // reform tree into array-based tree
        ArrayList<Integer> tree = new ArrayList<>();
        HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
        graph.put(-1, new ArrayList<>());
        int index = -1;
        // we use two Queue to store node and index
        Queue<TreeNode> q_node = new LinkedList<>();
        q_node.add(root);
        Queue<Integer> q_index = new LinkedList<>();
        q_index.add(index);

        while (q_node.size() > 0) {
            TreeNode node = q_node.poll();
            int parentIndex = q_index.poll();
            if (node != null) {
                index++;
                tree.add(node.val);
                graph.put(index, new ArrayList<>());
                graph.get(parentIndex).add(index);
                // push new node into Queue
                q_node.add(node.left);
                q_index.add(index);
                q_node.add(node.right);
                q_index.add(index);
            }
        }

        // represent the maximum start by node i with robbing i
        int[] dpRob = new int[index + 1];

        // represent the maximum start by node i without robbing i
        int[] dpNotRob = new int[index + 1];

        for (int i = index; i >= 0; i--) {
            ArrayList<Integer> children = graph.get(i);
            if (children == null || children.size() == 0) {
                // if is leaf
                dpRob[i] = tree.get(i);
                dpNotRob[i] = 0;
            } else {
                dpRob[i] = tree.get(i);
                for (int child : children) {
                    dpRob[i] += dpNotRob[child];
                    dpNotRob[i] += Math.max(dpRob[child], dpNotRob[child]);
                }
            }
        }

        return Math.max(dpRob[0], dpNotRob[0]);
    }
}