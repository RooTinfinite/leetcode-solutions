class Solution {
public:
    using ll = long long;

    struct Node {
        ll first, last, sum;

        Node(ll _first = -1, ll _last = -1, ll _sum = -1) : first(_first), last(_last), sum(_sum) {};

        void modify(ll _first = -1, ll _last = -1, ll _sum = 0) {
            first = _first;
            last = _last;
            sum = _sum;
        }
    };

    int tree_size;
    vector<Node> tree;

    void init(vector<int>& peak) {
        tree_size = 1;

        while(tree_size <= peak.size())
            tree_size <<= 1;

        tree.resize(tree_size << 1, Node());
        build(0, tree_size, 0, peak);
    }

    ll S(ll x) {
        if(x <= 0)
            return 0;
        return (x - 1) * (x - 2) / 2;
    }

    Node merge(const Node& L, const Node& R) {
        if(L.first < 0)
            return R;
        
        if(R.first < 0)
            return L;

        return Node(L.first, R.last, L.sum + R.sum + S(R.first - L.last + 1));
    }

    void build(int li, int ri, int ni, vector<int>& peak) {
        if(ri - li == 1) {
            if(li < peak.size() && peak[li])
                tree[ni].modify(li, li, 0);
            return;
        }

        int mid = (li + ri) >> 1;
        build(li, mid, ni * 2 + 1, peak);
        build(mid, ri, ni * 2 + 2, peak);
        tree[ni] = merge(tree[ni * 2 + 1], tree[ni * 2 + 2]);
    }

    void update(int li, int ri, int ni, int idx, int is_peak) {
        if(ri - li == 1) {
            if(is_peak) 
                tree[ni].modify(li, li, 0);
            else
                tree[ni].modify();
            return;
        }

        int mid = (li + ri) >> 1;

        if(idx < mid)
            update(li, mid, ni * 2 + 1, idx, is_peak);

        else
            update(mid, ri, ni * 2 + 2, idx, is_peak);

        tree[ni] = merge(tree[ni * 2 + 1], tree[ni * 2 + 2]);
    }

    Node query(int li, int ri, int ni, int l, int r) {
        if(li >= r || ri <= l) 
            return Node();

        if(l <= li && r >= ri)
            return tree[ni];

        int mid = (li + ri) >> 1;
        return merge(query(li, mid, ni * 2 + 1, l, r), query(mid, ri, ni * 2 + 2, l, r));
    }

    vector<ll> countOfPeaks(vector<int>& A, vector<vector<int>>& Q) {
        int n = A.size();
        vector<int> peak(n);

        for(int i = 1; i < n - 1; ++i)
            peak[i] = (A[i] > A[i - 1] && A[i] > A[i + 1]);

        init(peak);
        vector<ll> res;

        for(auto& q : Q) {
            if(q[0] == 1) {
                ll l = q[1], r = q[2], len = r - l + 1;
                res.push_back(0);

                if(len >= 3) {
                    Node N = query(0, tree_size, 0, l + 1, r);                    
                    ll total = S(len), no_peak = N.sum + S(N.first - l + 1) + S(r - N.last + 1);

                    if(N.first >= 0) 
                        res.back() = total - no_peak;
                }
            }

            else {
                int index = q[1], value = q[2];
                A[index] = value;

                auto check = [&](int i) -> void {
                    if(i > 0 && i < n - 1)
                        update(0, tree_size, 0, i, (A[i] > A[i - 1] && A[i] > A[i + 1]));
                };

                check(index - 1);
                check(index);
                check(index + 1);
            }
        }

        return res;
    }
};