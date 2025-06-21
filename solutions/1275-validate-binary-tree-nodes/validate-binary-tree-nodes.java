class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        if (root == -1) {
            return false;
        }
        
        Set<Integer> seen = new HashSet<>();
        Stack<Integer> stack = new Stack<>();
        seen.add(root);
        stack.push(root);
        
        while (!stack.isEmpty()) {
            int node = stack.pop();
            int[] children = {leftChild[node], rightChild[node]};
            
            for (int child : children) {
                if (child != -1) {
                    if (seen.contains(child)) {
                        return false;
                    }
                    
                    stack.push(child);
                    seen.add(child);
                }
            }
            
        }
        
        return seen.size() == n;
    }
    
    public int findRoot(int n, int[] left, int[] right) {
        Set<Integer> children = new HashSet<>();
        for (int node : left) {
            children.add(node);
        }
        
        for (int node : right) {
            children.add(node);
        }
        
        for (int i = 0; i < n; i++) {
            if (!children.contains(i)) {
                return i;
            }
        }
        
        return -1;
    }
}