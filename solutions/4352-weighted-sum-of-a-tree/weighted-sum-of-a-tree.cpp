class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {

        int n = parent.size();

        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        vector<int> depth(n);
        queue<int> q;

        depth[0] = 1;
        q.push(0);

        int h = 1;

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            for (int v : children[u]) {

                depth[v] = depth[u] + 1;

                h = max(h, depth[v]);

                q.push(v);
            }
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] *
                   (h - depth[i] + 1);
        }

        return ans;
    }
};