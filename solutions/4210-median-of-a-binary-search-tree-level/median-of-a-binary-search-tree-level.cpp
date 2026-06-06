/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int levelMedian(TreeNode* root, int level) {
        map<int, vector<int>> m1;

        deque<TreeNode*> q = {root};

        int cur_level{0};
        while (q.size()>0) {
            deque<TreeNode*> nxt;
            while (q.size()>0) {

                TreeNode* u = q.front();
                q.pop_front();
                m1[cur_level].push_back(u->val);
                if (u->left) {
                    nxt.push_back(u->left);
                }
                if (u->right) {
                    nxt.push_back(u->right);
                }


            }

            q = nxt;
            cur_level++;
        }

        vector<int> A = m1[level];
        if (A.size()==0) return -1;
      
        return A[A.size()/2];

        
        
    }
};