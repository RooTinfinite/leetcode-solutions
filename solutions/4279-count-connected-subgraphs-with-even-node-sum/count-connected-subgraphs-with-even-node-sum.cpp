#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets;

    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.assign(n, 0);
            for(int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int x) {
            if(x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int a, int b) {
            int pa = find(a), pb = find(b);
            if(pa == pb) return;

            if(rank[pa] < rank[pb]) parent[pa] = pb;
            else if(rank[pa] > rank[pb]) parent[pb] = pa;
            else {
                parent[pb] = pa;
                rank[pa]++;
            }
        }
    };

    void generate(int i, int n, vector<int>& curr) {
        subsets.push_back(curr);

        for(int idx = i; idx < n; idx++) {
            curr.push_back(idx);
            generate(idx + 1, n, curr);
            curr.pop_back();
        }
    }

    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        subsets.clear();
        vector<int> curr;
        generate(0, nums.size(), curr);

        int count = 0;

        for(auto &sub : subsets) {
            if(sub.size() == 0) continue;

            int sum = 0;
            for(int node : sub) sum += nums[node];
            if(sum % 2 != 0) continue;

            unordered_set<int> st(sub.begin(), sub.end());
            DSU dsu(nums.size());

            for(auto &e : edges) {
                int u = e[0], v = e[1];
                if(st.count(u) && st.count(v)) {
                    dsu.unite(u, v);
                }
            }

            unordered_set<int> parents;
            for(int x : sub) {
                parents.insert(dsu.find(x));
            }

            if(parents.size() == 1) count++;
        }

        return count;
    }
};