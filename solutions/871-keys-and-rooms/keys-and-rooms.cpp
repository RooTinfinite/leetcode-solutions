class Solution {
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        int n = rooms.size();
        std::vector<bool> vis(n, false);
        std::stack<int> stack;
        stack.push(0);
        vis[0] = true;
        int count = 1;

        while (!stack.empty()) {
            int currentRoom = stack.top();
            stack.pop();
            for (int key : rooms[currentRoom]) {
                if (!vis[key]) {
                    stack.push(key);
                    vis[key] = true;
                    count++;
                }
            }
        }
        return count == n;
    }
};