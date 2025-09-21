class Solution 
{
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) 
    {
        function<void(TreeNode*, vector<int>&)> dfs;
        dfs = [&](TreeNode* n, vector<int>& v)
        {
            if (n) dfs(n->left, v), v.push_back(n->val), dfs(n->right, v);
        };
        
        vector<int> nums;
        dfs(root, nums);
        
        vector<vector<int>> results;
        int n = nums.size();
        
        for (int q : queries)
        {
            int i = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            if (i < n && nums[i] == q) results.push_back({q,q});
            else
                if      (i == 0) results.push_back({-1, nums[0]});
                else if (i == n) results.push_back({nums[n-1], -1});
                else             results.push_back({nums[i-1], nums[i]});
        }
        
        return results;
    }
};