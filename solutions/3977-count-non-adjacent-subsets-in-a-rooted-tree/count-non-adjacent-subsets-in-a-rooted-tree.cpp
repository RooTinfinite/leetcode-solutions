using ll = long long;

class Solution {
public:
    ll mod = 1e9 + 7;
    
    vector<vector<ll>> helper(int cur, int k, int n, vector<int> &nums, vector<vector<int>> &adj) {
        vector<vector<ll>> ans(2, vector<ll> (k, 0)); // 0-> skip, 1-> take
        ans[1][nums[cur]] = 1;
        ans[0][0] = 1;
        
        vector<vector<ll>> ch, curState(2, vector<ll> (k, 0));
        for(auto nb : adj[cur]) {
            ch = helper(nb, k, n, nums, adj);
            // reset curState to 0 for all possible mod values
            for(int i = 0; i < 2; ++i) {
                for(int j = 0; j < k; ++j) curState[i][j] = 0;
            }
            // try to fill 0th row -> i.e. number of subsets for all mod values possible if we dont choose cur node
            for(int md = 0; md < k; ++md) {     // (lfHalf + rtHalf) % k == md
                for(int lfHalf = 0; lfHalf < k; ++lfHalf) {   // lfHalf -> left tree possible mod values
                    int rtHalf = (md - lfHalf + k) % k;   // rtHalf -> right tree possible mod values
                    ll newSubsets = ( ans[0][lfHalf] * ((ch[0][rtHalf] + ch[1][rtHalf])% mod) ) % mod;
                    curState[0][(lfHalf + rtHalf)% k] = (curState[0][(lfHalf + rtHalf)% k] + newSubsets) % mod;
                }
            }

            // try to fill 1st row -> i.e. number of subsets for all mod values possible if we choose cur node and then move forward
            for(int md = 0; md < k; ++md) {
                for(int lfHalf = 0; lfHalf < k; ++lfHalf) {
                    int rtHalf = (md - lfHalf + k) % k;
                    ll newSubsets = ( ans[1][lfHalf] * ch[0][rtHalf] ) % mod;
                    curState[1][(lfHalf + rtHalf)% k] = (curState[1][(lfHalf + rtHalf)% k] + newSubsets) % mod;
                }
            }

            // update prev such that it holds number of subsets for all mod values possible even before next child is explored
            ans = curState;
        }

        return ans;
    }
    
    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; ++i) {
            int p = parent[i];
            adj[p].push_back(i);
        }

        for(int i = 0; i < n; ++i) nums[i] = nums[i] % k;

        vector<vector<ll>> ans = helper(0, k, n, nums, adj);

        return (ans[0][0] + ans[1][0] - 1 + mod)% mod;
    }
};