class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        unordered_map<int, priority_queue<int>> umap;

        long long ans = 0;

        int n = value.size();

        for (int i = 0; i < n; i++) {
            umap[limit[i]].push(value[i]);
        }

        for (auto &[lim, pq]: umap) {
            for (int i = 0; i < lim && !pq.empty(); i++) {
                ans += pq.top();
                pq.pop();
            }
        }


        return ans;
    }
};