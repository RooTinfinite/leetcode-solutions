class Solution {
public:
    // modify Kahn's algorithm for undirected graph
    static int diameter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int> deg(n, 0);
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            const int v=e[0], w=e[1];
            adj[v].push_back(w);
            adj[w].push_back(v);
            deg[v]++, deg[w]++;// degree count
        }
        queue<int> q;
        for (int i=0; i < n; i++)
            if (deg[i] == 1)// Push leaves to q
                q.push(i);

        int level=0, left=n;
        //inward toward center
        for (; left>2; level++) { //may only 2 leaf nodes
            int qz=q.size();
            left-=qz;
            for (int i=0; i<qz; i++) {
                int v=q.front();
                q.pop();
                for (int w : adj[v]) {
                    // remove edge (v, w) s.t. w being a leaf
                    if (--deg[w]==1) q.push(w);
                }
            }
        }
    //    cout<<"left="<< left<<",level="<<level<<endl;
        return (left==2)?2*level+1:2*level;

    }

    static int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                         vector<vector<int>>& edges2) {
        int d1=diameter(edges1), d2=diameter(edges2);
        return max({d1, d2, (d1+1)/2+(d2+1)/2+1});
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();