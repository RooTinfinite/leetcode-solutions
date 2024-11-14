class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) {
            return {};
        }  

        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        mp[0] = {root->val};

        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int index = q.front().second;
            q.pop();

            if (cur->left) {
                q.push({cur->left, index-1});

                if (mp.find(index-1) == mp.end()) {
                    mp[index-1] = {cur->left->val};
                }
                else {
                    mp[index-1].push_back(cur->left->val);
                }
            }

            if (cur->right) {
                q.push({cur->right, index+1});

                if (mp.find(index+1) == mp.end()) {
                    mp[index+1] = {cur->right->val};
                }
                else {
                    mp[index+1].push_back(cur->right->val);
                }
            } 
        }  

        vector<vector<int>> result;
        for (auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};