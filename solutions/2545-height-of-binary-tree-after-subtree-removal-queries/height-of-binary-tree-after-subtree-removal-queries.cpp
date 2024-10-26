class Solution {
public:
    vector<int>dfsTree;
    int d[300005];
    int st[300005];
    int en[300005];
    void dfs(TreeNode *root, int dep) {
        if(root == NULL) {
            return;
        }

        d[root->val] = dep;
        st[root->val] = (int)dfsTree.size();
        dfsTree.push_back(root->val);
        dfs(root->left,dep+1);
        dfs(root->right,dep+1);
        en[root->val] = (int)dfsTree.size();
        dfsTree.push_back(root->val);

    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int>pref;
        vector<int>suf;
        dfs(root,0);
        int n = (int)dfsTree.size();
        for(int i = 0 ; i < n ; i++) {
            pref.push_back(d[dfsTree[i]]);
            suf.push_back(pref.back());
        }
        for(int i = 1 ; i < n ; i++) {
            pref[i] = max(pref[i],pref[i-1]);
        }
        for(int i = n-2 ; i >= 0 ; i--) {
            suf[i] = max(suf[i],suf[i+1]);
        }
        vector<int>ans;
        for(auto &x : queries) {
            int ST = st[x];
            int EN = en[x];
            int res = 0;
            if(ST-1 >= 0) {
                res = max(res,pref[ST-1]);
            }
            if(EN+1 < n) {
                res = max(res,suf[EN+1]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};