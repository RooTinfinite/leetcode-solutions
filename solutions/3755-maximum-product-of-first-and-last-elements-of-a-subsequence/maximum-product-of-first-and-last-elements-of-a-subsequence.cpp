typedef long long ll;
class Solution {
public:
    ll maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<ll> rmax(n, INT_MIN), rmin(n, INT_MAX);
        vector<ll> lmax(n, INT_MIN), lmin(n, INT_MAX);
        
        rmax[n-1] = nums[n-1];
        rmin[n-1] = nums[n-1];
        lmax[0] = nums[0];
        lmin[0] = nums[0];

        // Build suffix max/min
        for (int i = n-2; i >= 0; i--) {
            rmax[i] = max(rmax[i+1], (ll)nums[i]);
            rmin[i] = min(rmin[i+1], (ll)nums[i]);
        }

        ll res = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                lmax[i] = max(lmax[i-1], (ll)nums[i]);
                lmin[i] = min(lmin[i-1], (ll)nums[i]);
            }

            ll previ = i - m + 1;
            if (previ >= 0) {
                res = max(res, rmax[i] * lmax[previ]);
                res = max(res, rmin[i] * lmin[previ]);
            }
        }
        return res;
    }
};