class Solution {
public:
    std::vector<int> result;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;
    std::vector<int> needsFlip;
    
    void dfs(int node, int parent) {
        for (auto& [child, edgeIndex] : adjacencyList[node]) {
            if (child == parent) continue;
            dfs(child, node);

            if (needsFlip[child]) {
                result.push_back(edgeIndex);
                needsFlip[child] ^= 1;
                needsFlip[node] ^= 1;
            }
        }
    }
    
    std::vector<int> minimumFlips(int n, std::vector<std::vector<int>>& edges, std::string start, std::string target) {
        adjacencyList.assign(n, {});
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjacencyList[u].push_back({v, i});
            adjacencyList[v].push_back({u, i});
        }
        needsFlip.resize(n);
        for (int i = 0; i < n; ++i)
            needsFlip[i] = (start[i] != target[i]);

        dfs(0, -1);

        if (needsFlip[0]) return {-1};
        sort(result.begin(), result.end());
        return result;
    }
};