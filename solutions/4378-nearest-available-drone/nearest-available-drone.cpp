class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int tx = target[0], ty = target[1];
        auto key = [&](const auto& e) {
            const auto& [i, d] = e;
            int dist = abs(d[0] - tx) + abs(d[1] - ty);
            return pair{dist <= d[2] ? dist : INT_MAX, (int)i};   // unreachable sorts last
        };
        auto [dist, i] = ranges::min(drones | views::enumerate | views::transform(key));
        return dist == INT_MAX ? -1 : i;
    }
};