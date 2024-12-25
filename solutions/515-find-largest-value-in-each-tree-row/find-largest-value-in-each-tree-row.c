#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")
void preOrder(struct TreeNode* Node, int level, int* arr, int* sz) {
    if (Node == NULL) return;
    if (*sz <= level) {
        (*sz)++;
        arr[level]=INT_MIN;
    }
    arr[level] = (arr[level] > Node->val) ? arr[level] : Node->val;
    preOrder(Node->left, level + 1, arr, sz);
    preOrder(Node->right, level + 1, arr, sz);
}

int* largestValues(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int sz = 0; // Initialize the size of the result array
    int* arr=(int*)malloc(10001*sizeof(int));

    preOrder(root, 0, arr, &sz);

    *returnSize = sz;

    return arr;
}