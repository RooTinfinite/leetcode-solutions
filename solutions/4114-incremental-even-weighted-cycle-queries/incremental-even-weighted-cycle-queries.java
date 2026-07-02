class Solution {
    class DSU {
        int[] parent;
        int[] parity;
        int[] rank;

        public DSU(int n) {
            parent = new int[n];
            parity = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                parity[i] = 0;
                rank[i] = 1;
            }
        }

        // Returns the root. The parity array is updated during path compression.
        public int find(int x) {
            if (parent[x] == x) {
                return x;
            }
            int originalParent = parent[x];
            int root = find(originalParent);
            
            // Accumulate the parity from the original parent
            parity[x] ^= parity[originalParent];
            parent[x] = root;
            
            return root;
        }

        public void join(int x, int y, int w) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) return;

            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                rank[rootX] += rank[rootY];
                parent[rootY] = rootX;
                parity[rootY] = parity[y] ^ w ^ parity[x];
            } else {
                rank[rootY] += rank[rootX];
                parent[rootX] = rootY;
                parity[rootX] = parity[x] ^ w ^ parity[y];
            }
        }
        
        // Helper to get the parity of a node to its root
        public int getParity(int x) {
            return parity[x];
        }
    }

    public int numberOfEdgesAdded(int n, int[][] edges) {
        DSU graph = new DSU(n);
        int ans = 0;

        for (int[] v : edges) {
            int x = v[0];
            int y = v[1];
            int w = v[2];

            int rootX = graph.find(x);
            int rootY = graph.find(y);

            // If they share the same root, a cycle is formed
            if (rootX == rootY) {
                int pathSumFromX = graph.getParity(x);
                int pathSumFromY = graph.getParity(y);

                // Check if the cycle parity is even
                if ((pathSumFromX ^ pathSumFromY ^ w) == 0) {
                    ans++;
                }
            } 
            // If different roots, no cycle is formed, just join them
            else {
                ans++;
                graph.join(x, y, w);
            }
        }
        return ans;
    }
}