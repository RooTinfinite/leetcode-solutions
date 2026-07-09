class Solution {
public:
    vector<long long> zigzagLevelSum(TreeNode* root) {
        int maxLevel = 0;
        getMaxLevel(root, 1, maxLevel);
        vector<long long> res(maxLevel, 0);
        deque<TreeNode*> dq;
        dq.push_back(root);
        int direction = 0, i = 0;
        while (!dq.empty()) {
            deque<TreeNode*> nxt;
            long long sum = 0;
            bool isGoodNode = true;
            while (!dq.empty()) {
                if (direction == 0) {
                    TreeNode* node = dq.front();
                    dq.pop_front();
                    if (!node->left)
                        isGoodNode = false;
                    if (isGoodNode)
                        sum += node->val;
                    if (node->left)
                        nxt.push_back(node->left);
                    if (node->right)
                        nxt.push_back(node->right);
                }
                else if (direction == 1) {
                    TreeNode* node = dq.back();
                    dq.pop_back();
                    if (!node->right)
                        isGoodNode = false;
                    if (isGoodNode)
                        sum += node->val;
                    if (node->right)
                        nxt.push_front(node->right);
                    if (node->left)
                        nxt.push_front(node->left);
                }
            }
            
            dq = nxt;
            res[i] = sum;
            i++;
            direction = 1 - direction;
        }
        return res;
    }
    
    void getMaxLevel(TreeNode* root, int curLevel, int& maxLevel) {
        if (!root)
            return;
        maxLevel = max(maxLevel, curLevel);
        getMaxLevel(root->left, curLevel + 1, maxLevel);
        getMaxLevel(root->right, curLevel + 1, maxLevel);
    }
};