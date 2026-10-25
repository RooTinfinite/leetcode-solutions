class Solution {

    Map<Integer, Integer> map = new HashMap<>();

    public int pathSum(int[] nums) {
        // Store the data in a hashmap, with the coordinates as the key and the
        // node value as the value
        for (int num : nums) {
            int key = num / 10;
            int value = num % 10;
            map.put(key, value);
        }

        return dfs(nums[0] / 10, 0);
    }

    private int dfs(int root, int preSum) {
        // Find the level and position values from the coordinates
        int level = root / 10;
        int pos = root % 10;

        //the left child and right child position in the tree
        int left = (level + 1) * 10 + pos * 2 - 1;
        int right = (level + 1) * 10 + pos * 2;
        int currSum = preSum + map.get(root);

        // If the node is a leaf node, return its root to leaf path sum.
        if (!map.containsKey(left) && !map.containsKey(right)) {
            return currSum;
        }

        // Otherwise iterate through the left and right children recursively
        // using depth first search
        int leftSum = map.containsKey(left) ? dfs(left, currSum) : 0;
        int rightSum = map.containsKey(right) ? dfs(right, currSum) : 0;

        //return the total path sum of the tree rooted at the current node
        return leftSum + rightSum;
    }
}