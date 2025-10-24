template <typename T, typename F = function<bool(const T&, const T&)>>
struct linear_rmq {
    vector<T> values;
    F compare;
    vector<int> head;
    vector<array<unsigned,2>> masks;

    linear_rmq() {}

    linear_rmq(const vector<T>& arr, F cmp = F{})
      : values(arr), compare(cmp),
        head(arr.size()+1),
        masks(arr.size())
    {
        vector<int> monoStack{-1};
        int n = arr.size();
        for (int i = 0; i <= n; i++) {
            int last = -1;
            while (monoStack.back() != -1 &&
                   (i == n || !compare(values[monoStack.back()], values[i])))
            {
                if (last != -1) head[last] = monoStack.back();
                unsigned diffBit = __bit_floor(unsigned(monoStack.end()[-2] + 1) ^ i);
                masks[monoStack.back()][0] = last = (i & -diffBit);
                monoStack.pop_back();
                masks[monoStack.back() + 1][1] |= diffBit;
            }
            if (last != -1) head[last] = i;
            monoStack.push_back(i);
        }
        for (int i = 1; i < n; i++) {
            masks[i][1] = (masks[i][1] | masks[i-1][1])
                        & -(masks[i][0] & -masks[i][0]);
        }
    }

    T query(int L, int R) const {
        unsigned common = masks[L][1] & masks[R][1]
                        & -__bit_floor((masks[L][0] ^ masks[R][0]) | 1);
        unsigned k = masks[L][1] ^ common;
        if (k) {
            k = __bit_floor(k);
            L = head[(masks[L][0] & -k) | k];
        }
        k = masks[R][1] ^ common;
        if (k) {
            k = __bit_floor(k);
            R = head[(masks[R][0] & -k) | k];
        }
        return compare(values[L], values[R]) ? values[L] : values[R];
    }
};

template<typename T, typename Compare>
vector<int> closest_right(const vector<T>& a, Compare cmp) {
    int n = a.size(); vector<int> closest(n); iota(begin(closest), end(closest), 0);
    for (int i = n - 1; i >= 0; i--) {
        auto& j = closest[i];
        while(j < n - 1 && cmp(a[i], a[j + 1])) j = closest[j + 1];
    }
    return closest;
}

using ll = long long;

class Solution {
public:
    long long maxTotalValue(vector<int>& a, int k) {
        const int n = a.size();
        vector<int> ID(n);
        iota(begin(ID), end(ID), 0);
        linear_rmq<int> mx(ID, [&](int x, int y) {return a[x] > a[y];});
        linear_rmq<int> mn(ID, [&](int x, int y) {return a[x] < a[y];});
        auto f = [&](ll x) -> ll {
            ll cnt = (ll)n * (n + 1) / 2;
            for(int l = 0, r = 0; r < n; r++) {
                while(l <= r && a[mx.query(l, r)] - a[mn.query(l, r)] >= x) {
                    l++;
                }
                cnt -= r - l + 1;
            }
            return cnt;
        };
        ll base = 0;
        {
            ll left = 0, right = *max_element(begin(a), end(a)) - *min_element(begin(a), end(a));
            while(left <= right) {
                ll middle = (left + right) / 2;
                if(f(middle) >= k) base = middle, left = middle + 1;
                else right = middle - 1;
            }
        }
        vector<ll> suff_mx(n + 1);
        vector<ll> suff_mn(n + 1);
        auto rmx = closest_right(a, greater_equal<int>());
        auto rmn = closest_right(a, less_equal<int>());
        for(int i = n - 1; i >= 0; i--) {
            suff_mx[i] = suff_mx[rmx[i] + 1] + (ll)a[i] * (rmx[i] - i + 1);
            suff_mn[i] = suff_mn[rmn[i] + 1] + (ll)a[i] * (rmn[i] - i + 1);
        }
        auto query_mn = [&](int L, int R) -> ll {
            if(L > R) return 0;
            int id = mn.query(L, R);
            return suff_mn[L] - suff_mn[id] + (ll)a[id] * (R - id + 1);
        };
        auto query_mx = [&](int L, int R) -> ll {
            if(L > R) return 0;
            int id = mx.query(L, R);
            return suff_mx[L] - suff_mx[id] + (ll)a[id] * (R - id + 1);
        };
        ll res = 0;
        for(int i = 0; i < n; i++) {
            int left = i, right = n - 1, id = -1;
            while(left <= right) {
                int middle = (left + right) >> 1;
                if(a[mx.query(i, middle)] - a[mn.query(i, middle)] >= base) id = middle, right = middle - 1;
                else left = middle + 1;
            }
            if(id == -1) break;
            ll max = suff_mx[i] - query_mx(i, id - 1);
            ll min = suff_mn[i] - query_mn(i, id - 1);
            res += max - min;
        }
        res -= (f(base) - k) * base;
        return res;
    }
};