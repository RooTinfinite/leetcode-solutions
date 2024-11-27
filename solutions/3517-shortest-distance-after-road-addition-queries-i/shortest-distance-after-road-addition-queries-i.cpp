#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define INL_ATTR noexcept INL NO_SAN HOT
#define OUTL_ATTR noexcept NO_SAN HOT
#define LAM_ATTR INL NO_SAN HOT noexcept

class Solution {
private:
    static constexpr uint16_t MAXN = 5000;
    static vector<vector<int>> graph;
    
    static void updateDistances(int current, vector<int>& distances) OUTL_ATTR {
        int newDist = distances[current] + 1;
        for (int neighbor : graph[current]) {
            if (distances[neighbor] <= newDist) continue;
            distances[neighbor] = newDist;
            updateDistances(neighbor, distances);
        }
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) OUTL_ATTR {
        vector<int> distances(n);
        for (int i = 0; i < n; ++i) {
            distances[i] = n - 1 - i;
        }
        
        graph.clear();
        graph.resize(n);
        for (int i = 0; i + 1 < n; ++i) {
            graph[i + 1].push_back(i);
        }
        
        vector<int> result;
        result.reserve(queries.size());
        
        for (const auto& query : queries) {
            int source = query[0];
            int target = query[1];
            
            graph[target].push_back(source);
            distances[source] = min(distances[source], distances[target] + 1);
            updateDistances(source, distances);
            
            result.push_back(distances[0]);
        }
        
        return result;
    }
};

vector<vector<int>> Solution::graph;

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();