class Solution {

    // DFS helper function
    public void dfs(int node, boolean[] vis, ArrayList<ArrayList<Integer>> al) {
        vis[node] = true;
        for (int neighbor : al.get(node)) {
            if (!vis[neighbor]) {
                dfs(neighbor, vis, al);
            }
        }
    }

    public int countComponents(int[] nums, int threshold) {
        int n = nums.length;

        // Sort the numbers in increasing order
        Arrays.sort(nums);

        // HashSet to store all numbers <= threshold
        HashSet<Integer> hs = new HashSet<>();

        // Adjust the length n to reflect how many numbers are <= threshold
        int adjustedLength = n;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > threshold) {
                adjustedLength = i;
                break;
            }
        }

        // Fill the set with numbers <= threshold
        for (int i = 0; i < adjustedLength; i++) {
            hs.add(nums[i]);
        }

        // Create an adjacency list for the numbers <= threshold
        ArrayList<ArrayList<Integer>> al = new ArrayList<>();
        for (int i = 0; i <= threshold; i++) {
            al.add(new ArrayList<>());
        }

        // Count the numbers greater than threshold initially
        int res = nums.length - adjustedLength;

        // Build the adjacency list based on LCM
        for (int i = 0; i < adjustedLength; i++) {
            int curr = nums[i];
            int x = 2;
            while ((long) x * curr <= threshold) {
                // Add an undirected edge between curr and x * curr
                al.get(curr).add(x * curr);
                al.get(x * curr).add(curr);
                x++;
            }
        }

        // Visited array to keep track of visited numbers
        boolean[] vis = new boolean[threshold + 1];

        // Traverse the graph and count components using DFS
        for (int i = 1; i <= threshold; i++) {
            if (!hs.contains(i)) {
                continue;
            }
            if (!vis[i]) {
                // Perform DFS from the current unvisited node
                dfs(i, vis, al);
                res++; // Increment the component count
            }

        }
        return res;
    }
}