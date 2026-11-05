class Solution {
    int getColor(char c) {
        if(c == 'R') return 0; 
        if(c == 'B') return 1; 
        return 2; 
    }
    public int findColoredRoot(int[][] edges, String colors) {
        // r=0, b = 1, w = 2
        // next color = (cu + 1) % 3
        // at most two children 
        int n = colors.length(); 
        int ind[] = new int[n]; 
        int oud[] = new int[n]; 

        for(int i = 0; i < n - 1; i++) {
            int u = edges[i][0]; 
            int v = edges[i][1]; 
            int cu = getColor(colors.charAt(u)); 
            int cv = getColor(colors.charAt(v)); 

            if(cu == cv) return -1; // not possible 
            // we want the edge in forward direction means r -> b || b -> w || w -> r 
            if((cv - cu + 3)%3 == 1) {
                // connect u -> v 
                oud[u]++; 
                ind[v]++; 
            } else {
                // connect v -> u 
                oud[v]++; 
                ind[u]++; 
            }
        }
        int root = -1; // any root 

        for(int i = 0; i < n; i++) {
            // each node must have a ind - only 1 or none 
            // out < 2 
            if(oud[i] > 2 || ind[i] > 1) return -1; 
            if(ind[i] == 0) {
                if(root != -1) return -1; // two can not be root 
                // this can be root 
                root = i; 
            }
        }
        return root; 
    }
}