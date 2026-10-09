class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        // construct the graph from the given highways array
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < highways.size(); ++i) {
            int u = highways[i][0], v = highways[i][1], toll = highways[i][2];
            graph[u].push_back({v, toll});
            graph[v].push_back({u, toll});
        }

        // Min-heap priority queue to store tuples of (cost, city,
        // discountsUsed)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        pq.push(make_tuple(
            0, 0, 0));  // Start from city 0 with cost 0 and 0 discounts used

        // 2D array to track minimum distance to each city with a given number
        // of discounts used
        vector<vector<int>> dist(n, vector<int>(discounts + 1, INT_MAX));
        dist[0][0] = 0;

        vector<vector<bool>> visited(n, vector<bool>(discounts + 1, false));

        while (!pq.empty()) {
            int currentCost, city, discountsUsed;
            tie(currentCost, city, discountsUsed) = pq.top();
            pq.pop();

            // Skip processing if already visited with the same number of
            // discounts used
            if (visited[city][discountsUsed]) {
                continue;
            }
            visited[city][discountsUsed] = true;

            // Explore all neighbors of the current city
            for (int i = 0; i < graph[city].size(); ++i) {
                int neighbor = graph[city][i].first;
                int toll = graph[city][i].second;

                // Case 1: Move to the neighbor without using a discount
                if (currentCost + toll < dist[neighbor][discountsUsed]) {
                    dist[neighbor][discountsUsed] = currentCost + toll;
                    pq.push(make_tuple(dist[neighbor][discountsUsed], neighbor,
                                       discountsUsed));
                }

                // Case 2: Move to the neighbor using a discount if available
                if (discountsUsed < discounts) {
                    int newCostWithDiscount = currentCost + toll / 2;
                    if (newCostWithDiscount <
                        dist[neighbor][discountsUsed + 1]) {
                        dist[neighbor][discountsUsed + 1] = newCostWithDiscount;
                        pq.push(make_tuple(newCostWithDiscount, neighbor,
                                           discountsUsed + 1));
                    }
                }
            }
        }

        // Find the minimum cost to reach city n-1 with any number of discounts
        // used
        int minCost = *min_element(dist[n - 1].begin(), dist[n - 1].end());
        return minCost == INT_MAX ? -1 : minCost;
    }
};