class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& es, string S, vector<string>& qs) {
        vector<int> pa(n, 0);
        vector<int> deg(n, 0);
        deg[0] = 2;  // Set root degree to avoid it being treated as a leaf
        for (auto& e : es) {
            int a = e[0], b = e[1];
            pa[a] ^= b, pa[b] ^= a;  // Store XOR sum of neighbors
            ++deg[a], ++deg[b];
        }

        vector<int> siz(n, 1);
        vector<int> ch(n, -1);
        vector<int> qu;
        for (int i = 0; i < n; ++i) if (deg[i] == 1) qu.push_back(i);  // Start from leaves
        
        for (int idx = 0; idx < qu.size(); ++idx) {
            int i = qu[idx];
            int p = pa[i];  // Current XOR sum contains only the parent
            int s = siz[i];
            siz[p] += s;
            if (ch[p] == -1 or s > siz[ch[p]]) ch[p] = i;  // Identify heavy child
            pa[p] ^= i;  // Remove child from parent's XOR sum to isolate grandparent/parent
            if (--deg[p] == 1) qu.push_back(p);
        }
        qu.push_back(0);

        vector<int> top(n, -1);
        vector<int> dfn(n, -1);
        vector<int> l(n);
        int t = 0;
        for (int idx = qu.size(); idx--; ) {  // Top-down traversal to establish HLD
            int i = qu[idx];
            if (~dfn[i]) continue;
            for (int tt = i; ~i; i = ch[i]) {
                top[i] = tt;
                l[t] = 1 << S[i] - 'a';
                dfn[i] = t++;
            }
        }

        // O(n) BIT construction
        vector<int> bit(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            bit[i] ^= l[i - 1];
            int j = i + (i & -i);
            if (j <= n) bit[j] ^= bit[i];
        }

        vector<bool> ans;
        for (const string& qq : qs) {
            stringstream ss(qq);
            string typ;
            ss >> typ;
            if (typ[0] == 'u') {  // Point update logic
                int i; char c; ss >> i >> c;
                int x = dfn[i];
                int v = 1 << c - 'a';
                int d = v ^ l[x];
                l[x] = v;
                for (++x; x <= n; x += x & -x) bit[x] ^= d;
            } else {  // Path query logic
                int a, b; ss >> a >> b;
                int res = 0;
                while (top[a] != top[b]) {
                    if (dfn[top[a]] < dfn[top[b]]) swap(a, b);
                    int s = dfn[top[a]], t = dfn[a] + 1;
                    for (; t > s; t &= t - 1) res ^= bit[t];  // Efficient range XOR query
                    for (; s > t; s &= s - 1) res ^= bit[s];
                    a = pa[top[a]];
                }
                if (dfn[a] > dfn[b]) swap(a, b);
                int s = dfn[a], t = dfn[b] + 1;
                for (; t > s; t &= t - 1) res ^= bit[t];
                for (; s > t; s &= s - 1) res ^= bit[s];
                ans.push_back((res & (res - 1)) == 0);  // Check if at most one bit is set
            }
        }
        return ans;
    }
};