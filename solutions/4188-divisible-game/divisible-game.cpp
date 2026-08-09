#include <bits/stdc++.h>
#include <vector>
using namespace std;

using ll   = long long;
using pii  = pair<int, int>;
using vi   = vector<int>;
using vl   = vector<ll>;
using vvi  = vector<vector<int>>;

#define pb        push_back
#define all(x)    (x).begin(), (x).end()
#define sz(x)     (int)(x).size()
#define rep(i, n) for (int i = 0; i < (n); ++i)

const int inf  = 1e9;
const ll  linf = 4e18;
const int mod  = 1e9 + 7;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? (a = b, true) : false; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? (a = b, true) : false; }

class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        int n = sz(nums);
        // A - B -> maximise, smallest k
        // prod(k, max score)%mod
        // kadane check for best k

        set<int> candidates;

        for(int x : nums){
            for(int d=1; d*d <= x; d++){
                if(x%d) continue;
                if(d>1)
                    candidates.insert(d);
                int opp = x/d;
                if(opp>1)
                    candidates.insert(opp);
            }
        }

        candidates.insert(2); // handles the case where no candidate divides any element

        auto check = [&](int poss) -> ll{
            ll res = -inf, cur = -inf;

            for(int x : nums){
                ll val = x%poss ? -x : x;
                if(cur == -inf)
                    cur = val;
                else
                    cur = max(val, cur + val);
                res = max(res, cur);
            }

            return res;
        };

        ll prod = 2;

        ll kcur = 2, mxScore = -inf;

        for(auto &x : candidates){
            ll score = check(x);

            if(score > mxScore){
                kcur = x;
                mxScore = score;
                prod = (score * x) % mod;
            }
        }

        return ((((mxScore%mod)+mod)%mod) * kcur) % mod;
    }
};