class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        boolean[] vis = new boolean[n];
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        vis[0] = true;
        int count = 1;

        while (!stack.isEmpty()) {
            int currentRoom = stack.pop();
            for (int key : rooms.get(currentRoom)) {
                if (!vis[key]) {
                    stack.push(key);
                    vis[key] = true;
                    count++;
                }
            }
        }
        return count == n;
    }
}