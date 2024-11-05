class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long total = 0;
        int n = costs.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int left = 0;
        int right = n - 1;

        for (int i = 0; i < candidates; ++i) {
            if (left <= right) {
                pq.emplace(costs[left], left);
                ++left;
            }
            if (left <= right) {
                pq.emplace(costs[right], right);
                --right;
            }
        }

        for (int i = 0; i < k; ++i) {
            auto [cost, index] = pq.top();
            pq.pop();
            total += cost;

            if (index < left) {
                if (left <= right) {
                    pq.emplace(costs[left], left);
                    ++left;
                }
            } else {
                if (left <= right) {
                    pq.emplace(costs[right], right);
                    --right;
                }
            }
        }

        return total;
    }
};