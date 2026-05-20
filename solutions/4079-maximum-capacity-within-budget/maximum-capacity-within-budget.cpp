class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();

        // Sort the values by (cost, capacity)
        vector<int> cap_sorted, cost_sorted;
        cap_sorted.reserve(n);
        cost_sorted.reserve(n);

        vector<pair<int,int>> pairs;
        pairs.reserve(n);
        for (int i = 0; i < n; ++i) 
            pairs.push_back({costs[i], capacity[i]});
        sort(pairs.begin(), pairs.end());

        for (auto &p : pairs) {
            cost_sorted.push_back(p.first);
            cap_sorted.push_back(p.second);
        }

        // Calculate max capacity prefix
        vector<int> cap_prefix(n, 0);
        for (int i = 0; i < n; ++i)
            cap_prefix[i] = max((i > 0 ? cap_prefix[i - 1] : 0), cap_sorted[i]);

        // One machine
        int result = 0;
        int last_single = (lower_bound(cost_sorted.begin(), cost_sorted.end(), budget) - cost_sorted.begin()) - 1;
        if (last_single >= 0)
            result = cap_prefix[last_single];

        // Two machines
        for (int i = 0; i < n; ++i) {
            int cst = cost_sorted[i];
            if (cst >= budget) // Costs sorted => next ones all >= budget
                break;

            // Try to find another machine to increase capacity with budget left
            int limit = budget - cst;
            int j = (lower_bound(cost_sorted.begin(), cost_sorted.end(), limit) - cost_sorted.begin()) - 1;
            j = min(j, i - 1);

            // If second machine exist, try to update the result
            if (j >= 0)
                result = max(result, cap_sorted[i] + cap_prefix[j]);
        }

        return result;
    }
};