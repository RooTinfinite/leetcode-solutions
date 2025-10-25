using ll = long long;

struct LazySGT {
    ll sz;
    vector<ll> _min_tree, _max_tree, lazy;
    
    void build(ll v, ll l, ll r, const vector<ll>& a) {
        if (l == r) {
            _min_tree[v] = a[r];
            _max_tree[v] = a[r];
            return;
        }
        ll m = (l + r) / 2;
        build(2 * v, l, m, a);
        build(2 * v + 1, m + 1, r, a);
        _min_tree[v] = min(_min_tree[2 * v], _min_tree[2 * v + 1]);
        _max_tree[v] = max(_max_tree[2 * v], _max_tree[2 * v + 1]);
    }
    
    void push(ll node, ll start, ll end) {
        if (lazy[node] != 0) {
            _min_tree[node] += lazy[node];
            _max_tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    
    void update_range(ll node, ll start, ll end, ll l, ll r, ll val) {
        push(node, start, end);
        if (start > end or start > r or end < l)
            return;
        if (l <= start and end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        ll mid = (start + end) / 2;
        update_range(2 * node, start, mid, l, r, val);
        update_range(2 * node + 1, mid + 1, end, l, r, val);
        _min_tree[node] = min(_min_tree[2 * node], _min_tree[2 * node + 1]);
        _max_tree[node] = max(_max_tree[2 * node], _max_tree[2 * node + 1]);
    }
    
    ll find_leftmost_zero(ll node, ll start, ll end) {
        push(node, start, end);
        if (_min_tree[node] > 0 or _max_tree[node] < 0)
            return -1;
        if (start == end)
            return start;
        ll mid = (start + end) / 2;
        ll left = find_leftmost_zero(2 * node, start, mid);
        if (left != -1)
            return left;
        return find_leftmost_zero(2 * node + 1, mid + 1, end);
    }
    
    LazySGT(ll n) : sz(n) {
        _min_tree.resize(4 * n, 0);
        _max_tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        vector<ll> a(n, 0);
        build(1, 0, n - 1, a);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        
        LazySGT st(n);
        unordered_map<int, int> prev;
        
        for (int r = 0; r < n; r++) {
            int v = nums[r];
            int val = (v % 2 == 0) ? 1 : -1;
            
            if (prev.find(v) != prev.end()) {
                st.update_range(1, 0, n - 1, 0, prev[v], -val);
            }
            
            st.update_range(1, 0, n - 1, 0, r, val);
            prev[v] = r;
            
            ll l = st.find_leftmost_zero(1, 0, n - 1);
            if (l != -1 and l <= r) {
                res = max(res, r - (int)l + 1);
            }
        }
        
        return res;
    }
};