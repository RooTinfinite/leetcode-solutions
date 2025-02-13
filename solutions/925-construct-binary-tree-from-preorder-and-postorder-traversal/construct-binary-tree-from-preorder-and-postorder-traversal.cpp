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
TreeNode* Pre_and_Post(const vector<int> &PreOrder, const vector<int> &PostOrder, int PreStart, int PreEnd, int PostStart, int PostEnd, unordered_map<int, int> &postMap){

    if(PreStart > PreEnd){
        return nullptr;
    }

    TreeNode* root = new TreeNode(PreOrder[PreStart]);
    
    if(PreStart == PreEnd){
        return root;
    }
    int leftChildVal = PreOrder[PreStart + 1];
    int leftChildIndexPost = postMap[leftChildVal];

    
    int leftSubtreeSize = leftChildIndexPost - PostStart + 1;

    
    root->left = Pre_and_Post(PreOrder, PostOrder, 
                              PreStart + 1, PreStart + leftSubtreeSize, 
                              PostStart, leftChildIndexPost, postMap);

    root->right = Pre_and_Post(PreOrder, PostOrder, 
                               PreStart + leftSubtreeSize + 1, PreEnd, 
                               leftChildIndexPost + 1, PostEnd - 1, postMap);

    return root;

}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int size = preorder.size();

    unordered_map<int, int> map;

    for(int i = 0; i < size; i++){
        map[postorder[i]] = i;
    }

    return Pre_and_Post(preorder, postorder, 0, size - 1, 0 , size - 1, map);

}

};