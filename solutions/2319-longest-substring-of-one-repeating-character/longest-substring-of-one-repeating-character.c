typedef struct {
    int pre, suf, maxLen;
    char leftChar, rightChar;
} Node;

void pushUp(Node* tree, int u, int l, int r) {
    int mid = (l + r) >> 1;
    int leftLen = mid - l + 1, rightLen = r - mid;
    int left = u << 1, right = u << 1 | 1;
    tree[u].leftChar = tree[left].leftChar;
    tree[u].rightChar = tree[right].rightChar;
    tree[u].pre = tree[left].pre;
    if (tree[left].pre == leftLen &&
        tree[left].rightChar == tree[right].leftChar) {
        tree[u].pre = tree[left].pre + tree[right].pre;
    }
    tree[u].suf = tree[right].suf;
    if (tree[right].suf == rightLen &&
        tree[left].rightChar == tree[right].leftChar) {
        tree[u].suf = tree[right].suf + tree[left].suf;
    }
    tree[u].maxLen = (int)fmax(tree[left].maxLen, tree[right].maxLen);
    if (tree[left].rightChar == tree[right].leftChar) {
        tree[u].maxLen =
            (int)fmax(tree[u].maxLen, tree[left].suf + tree[right].pre);
    }
}

void build(Node* tree, char* str, int u, int l, int r) {
    if (l == r) {
        tree[u].pre = 1;
        tree[u].suf = 1;
        tree[u].maxLen = 1;
        tree[u].leftChar = str[l];
        tree[u].rightChar = str[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(tree, str, u << 1, l, mid);
    build(tree, str, u << 1 | 1, mid + 1, r);
    pushUp(tree, u, l, r);
}

void update(Node* tree, int u, int l, int r, int pos, char ch) {
    if (l == r) {
        tree[u].leftChar = ch;
        tree[u].rightChar = ch;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        update(tree, u << 1, l, mid, pos, ch);
    } else {
        update(tree, u << 1 | 1, mid + 1, r, pos, ch);
    }
    pushUp(tree, u, l, r);
}

int* longestRepeating(char* s, char* queryCharacters, int* queryIndices,
                      int queryIndicesSize, int* returnSize) {
    int n = strlen(s);
    Node* tree = (Node*)malloc(4 * n * sizeof(Node));
    memset(tree, 0, 4 * n * sizeof(Node));
    build(tree, s, 1, 0, n - 1);
    int* ans = (int*)malloc(queryIndicesSize * sizeof(int));
    *returnSize = queryIndicesSize;
    for (int i = 0; i < queryIndicesSize; i++) {
        update(tree, 1, 0, n - 1, queryIndices[i], queryCharacters[i]);
        ans[i] = tree[1].maxLen;
    }
    free(tree);
    return ans;
}