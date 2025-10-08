class Solution {
public:
    unsigned n, bmask, k;
    vector<vector<int>> dp;
    vector<int> ans;

    bool dfs(unsigned mask, int r, vector<int>& arr, vector<int>& nums) {
        if (mask == bmask) {
            if (r==0) {
                if (ans.empty()) ans=arr;
                return 1;
            }
            return 0;
        }
        if (dp[mask][r]!=-1) return dp[mask][r];

        bool ans=0;
        for (int i=0; i<n; i++) {
            if ((mask&(1<<i)) != 0) continue; // nums[i] is used

            int x=nums[i], m=1;
            for (; x>0; x/=10)
                m*=10;
            int r2=((r*m)+nums[i])%k;
            arr.push_back(nums[i]);
            ans|= dfs(mask|(1<<i), r2, arr, nums);
            arr.pop_back(); // backtracking
            if (ans) break; // early stop
        }
        return dp[mask][r]=ans;
    }

    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        n=nums.size();
        this->k=k;
        bmask=(1<<n)-1;
        dp.assign(bmask+1, vector<int>(k, -1));
        sort(nums.begin(), nums.end());// least permutation first
        vector<int> arr;
        dfs(0, 0, arr, nums);
        if (ans.empty()) return {};
        return ans;
    }
};