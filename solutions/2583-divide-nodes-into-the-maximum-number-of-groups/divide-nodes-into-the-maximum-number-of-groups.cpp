
#include <vector>
#include <bitset>
#include <numeric>
#include <ranges>
#include <functional>

using namespace std;

class Solution {
public:
    int magnificentSets(int numNodes, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(numNodes);
        
        // Construct adjacency list
        for (const auto& edge : edges) {
            int nodeA = edge[0] - 1;
            int nodeB = edge[1] - 1;
            adjacencyList[nodeA].push_back(nodeB);
            adjacencyList[nodeB].push_back(nodeA);
        }

        vector<int> nodeColors(numNodes, UNCOLORED);
        vector<vector<int>> connectedComponents;
        
        // Identify connected components and check for bipartiteness
        for (int node : views::iota(0, numNodes)) {
            if (nodeColors[node] != UNCOLORED) continue;
            if (!isBipartiteDFS(node, adjacencyList, BLACK, nodeColors, connectedComponents.emplace_back())) 
                return -1;
        }

        // Compute the maximum number of groups
        return transform_reduce(
            begin(connectedComponents), end(connectedComponents), 0, plus{},
            [&adjacencyList](const auto& component) { return maxGroupsForComponent(component, adjacencyList); }
        );
    }

private:
    static constexpr int UNCOLORED = -1;
    static constexpr int BLACK = 0;
    static constexpr int WHITE = 1;

    // Depth-first search to check bipartiteness and extract connected components
    static bool isBipartiteDFS(int currentNode, const vector<vector<int>>& adjacencyList, 
                               int currentColor, vector<int>& nodeColors, vector<int>& component) {
        int oppositeColor = !currentColor;
        nodeColors[currentNode] = currentColor;
        component.push_back(currentNode);
        
        for (int neighbor : adjacencyList[currentNode]) {
            if (nodeColors[neighbor] == currentColor ||
                (nodeColors[neighbor] == UNCOLORED &&
                 !isBipartiteDFS(neighbor, adjacencyList, oppositeColor, nodeColors, component)))
                return false;
        }
        return true;
    }

    // Find the maximum number of groups for a given connected component
    static int maxGroupsForComponent(const vector<int>& component, const vector<vector<int>>& adjacencyList) {
        if (component.size() == 1) return 1;

        vector<int> queue, nextQueue;
        int maxGroupCount = 0;
        
        for (int startNode : component) {
            queue.push_back(startNode);
            bitset<500> visited;
            visited.set(startNode);
            int groupCount = 0;
            
            while (!queue.empty()) {
                ++groupCount;
                for (int currentNode : queue) {
                    for (int neighbor : adjacencyList[currentNode]) {
                        if (visited[neighbor]) continue;
                        visited.set(neighbor);
                        nextQueue.push_back(neighbor);
                    }
                }
                swap(queue, nextQueue);
                nextQueue.clear();
            }
            maxGroupCount = max(maxGroupCount, groupCount);
        }
        return maxGroupCount;
    }
};