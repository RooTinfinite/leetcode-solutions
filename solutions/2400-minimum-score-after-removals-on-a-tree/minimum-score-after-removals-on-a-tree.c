struct ListNode *createListNode(int val) {
    struct ListNode *obj = (struct ListNode *)malloc(sizeof(struct ListNode));
    obj->val = val;
    obj->next = NULL;
    return obj;
}

void freeList(struct ListNode *list) {
    while (list) {
        struct ListNode *p = list;
        list = list->next;
        free(p);
    }
}

int calc(int part1, int part2, int part3) {
    return fmax(part1, fmax(part2, part3)) - fmin(part1, fmin(part2, part3));
}

int dfs2(int x, int f, int oth, int anc, int *nums, struct ListNode **adj,
         int sum, int *res) {
    int son = nums[x];
    for (struct ListNode *p = adj[x]; p != NULL; p = p->next) {
        int y = p->val;
        if (y == f) {
            continue;
        }
        son ^= dfs2(y, x, oth, anc, nums, adj, sum, res);
    }
    if (f == anc) {
        return son;
    }

    *res = fmin(*res, calc(oth, son, sum ^ oth ^ son));
    return son;
}

int dfs(int x, int f, int *nums, struct ListNode **adj, int sum, int *res) {
    int son = nums[x];
    for (struct ListNode *p = adj[x]; p != NULL; p = p->next) {
        int y = p->val;
        if (y == f) {
            continue;
        }
        son ^= dfs(y, x, nums, adj, sum, res);
    }
    for (struct ListNode *p = adj[x]; p != NULL; p = p->next) {
        int y = p->val;
        if (y == f) {
            dfs2(y, x, son, x, nums, adj, sum, res);
        }
    }
    return son;
}

int minimumScore(int *nums, int numsSize, int **edges, int edgesSize,
                 int *edgesColSize) {
    struct ListNode *adj[numsSize];
    for (int i = 0; i < numsSize; i++) {
        adj[i] = NULL;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        struct ListNode *nodeu = createListNode(u);
        nodeu->next = adj[v];
        adj[v] = nodeu;
        struct ListNode *nodev = createListNode(v);
        nodev->next = adj[u];
        adj[u] = nodev;
    }
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum ^= nums[i];
    }
    int res = INT_MAX;
    dfs(0, -1, nums, adj, sum, &res);
    for (int i = 0; i < numsSize; i++) {
        freeList(adj[i]);
    }

    return res;
}