class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> resAverages;
        if (!root) return resAverages;
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            double sum = 0;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            double avg = sum / levelSize;
            resAverages.push_back(avg);
        }
        return resAverages;
    }
};