#include <ranges>
#include <vector>
using namespace std;

class UnionFind {

    vector<int> parent;
    vector<int> rank;
    int numberOfGroupsWithConnectedComponents{};

public:
    UnionFind(int numberOfComponents) : numberOfGroupsWithConnectedComponents{ numberOfComponents } {
        parent.resize(numberOfComponents);

        //prior to C++20: iota(vectorName.begin(), vectorName.end(), startValue)
        ranges::iota(parent, 0);
        rank.assign(numberOfComponents, 1);
    }

    int findParent(int index) {
        if (parent[index] != index) {
            parent[index] = findParent(parent[index]);
        }
        return parent[index];
    }

    bool joinByRank(int indexOne, int indexTwo) {
        int first = findParent(indexOne);
        int second = findParent(indexTwo);

        if (cycleFound(first, second)) {
            return false;
        }

        --numberOfGroupsWithConnectedComponents;

        if (rank[first] > rank[second]) {
            parent[second] = first;
            rank[first] += rank[second];
        }
        else {
            parent[first] = second;
            rank[second] += rank[first];
        }
        return true;
    }

    bool cycleFound(int parentFirst, int parentSecond) const {
        return parentFirst == parentSecond;
    }

    bool allComponentsAreConnectedWithoutCycles() const {
        return numberOfGroupsWithConnectedComponents == 1;
    }
};

class Solution {

public:
    bool validTree(int numberOfNodes, const vector<vector<int>>& edges) const {
        if (edges.size() < numberOfNodes - 1) {
            return false;
        }

        UnionFind unionFind(numberOfNodes);
        for (const auto edge : edges) {
            if (!unionFind.joinByRank(edge[0], edge[1])) {
                return false;
            }
        }

        return unionFind.allComponentsAreConnectedWithoutCycles();
    }
};