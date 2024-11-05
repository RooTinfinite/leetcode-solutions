class UF {
    public:
        vector<int> p; //parent
        vector<int> height; //size
        UF(int n) {
            for(int i = 0; i < n; i++) {
                p.push_back(i);
                height.push_back(1);
            }
        }

        int find(int u) {
            return p[u] == u ? u : find(p[u]);
        }

        void merge(int root1, int root2) {
            if(root1 == root2) {
                return;
            }
            if(height[root1] < height[root2]) {
                swap(root1, root2);
            }
            p[root1] = root2;
            height[root2] = max(height[root2], 1 + height[root1]);
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UF uf(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    int root1 = uf.find(i);
                    int root2 = uf.find(j);
                    uf.merge(root1, root2);
                }
            }
        }
        
        set<int> components;
        for(int i = 0; i < n; i++) {
            components.insert(uf.find(i));
        }
        return components.size();
    }
};