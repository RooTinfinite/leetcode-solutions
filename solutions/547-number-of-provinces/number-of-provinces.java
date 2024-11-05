class UF {
    int[] p;
    int[] height;

    UF(int n) {
        p = new int[n];
        height = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
            height[i] = 1;
        }
    }

    int find(int u) {
        if (p[u] == u) return u;
        return find(p[u]);
    }

    void merge(int root1, int root2) {
        if (root1 == root2) return;
        if (height[root1] < height[root2]) {
            int temp = root1;
            root1 = root2;
            root2 = temp;
        }
        p[root2] = root1;
        height[root1] = Math.max(height[root1], 1 + height[root2]);
    }
}

class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        UF uf = new UF(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    int root1 = uf.find(i);
                    int root2 = uf.find(j);
                    uf.merge(root1, root2);
                }
            }
        }
        
        Set<Integer> components = new HashSet<>();
        for (int i = 0; i < n; i++) {
            components.add(uf.find(i));
        }
        
        return components.size();
    }
}