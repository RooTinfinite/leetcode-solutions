class Solution {
public:
    int colorId(char c){
        if(c == 'R') return 0;
        else if(c == 'B') return 1;
        return 2;
    }
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<int> indegree(n, 0), outdegree(n, 0);

        for(auto i:edges){
            int u = i[0], v = i[1];
            int cu = colorId(colors[u]);
            int cv = colorId(colors[v]);

            if(cu == cv) return -1;

            if((cu+1) % 3 == cv){
                outdegree[u]++;
                indegree[v]++;
            }else{
                outdegree[v]++;
                indegree[u]++;
            }
        }

        int root = -1;

        for(int i = 0; i < n; i++){
            if(outdegree[i] > 2) return -1;

            if(indegree[i] == 0){
                if(root != -1) return -1;
                root = i;
            }else if(indegree[i] != 1) return -1;
        }
        return root;
    }
};