class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_set<int> vis;
        queue<pair<int, int>> q;
        q.push({x, 0});
        vis.insert(x);
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            
            int num = curr.first, turn = curr.second;
            if (num == y)
                return turn;
            if (vis.find(num + 1) == vis.end())
            {
                q.push({num + 1, turn + 1});
                vis.insert(num + 1);
            }
            if (vis.find(num - 1) == vis.end() && num - 1 >= 0)
            {
                q.push({num - 1, turn + 1});
                vis.insert(num - 1);
            }
            if (num % 11 == 0 && vis.find(num / 11) == vis.end())
            {
                q.push({num / 11, turn + 1});
                vis.insert(num / 11);
            }
            if (num % 5 == 0 && vis.find(num / 5) == vis.end())
            {
                q.push({num / 5, turn + 1});
                vis.insert(num / 5);
            }
        }
        return -1;
    }
};