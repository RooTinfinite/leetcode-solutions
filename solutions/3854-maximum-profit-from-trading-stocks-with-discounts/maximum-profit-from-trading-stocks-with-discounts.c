typedef struct {
    int* dp0;
    int* dp1;
    int size;
} Result;

struct ListNode* creatListNode(int val) {
    struct ListNode* obj = (struct ListNode*)malloc(sizeof(struct ListNode));
    obj->val = val;
    obj->next = NULL;
    return obj;
}

void freeList(struct ListNode* list) {
    while (list) {
        struct ListNode* p = list;
        list = list->next;
        free(p);
    }
}

void dfs(int u, int n, int* present, int* future, struct ListNode** g,
         int budget, Result* result, int* visited) {
    if (visited[u]) {
        return;
    }

    visited[u] = 1;
    int cost = present[u];
    int dCost = present[u] / 2;
    // dp[u][state][budget]
    // state = 0: Do not purchase parent node, state = 1: Must purchase parent
    // node
    int* dp0 = (int*)calloc(budget + 1, sizeof(int));
    int* dp1 = (int*)calloc(budget + 1, sizeof(int));
    // subProfit[state][budget]
    // state = 0: discount not available, state = 1: discount available
    int* subProfit0 = (int*)calloc(budget + 1, sizeof(int));
    int* subProfit1 = (int*)calloc(budget + 1, sizeof(int));
    int uSize = cost;

    for (struct ListNode* p = g[u]; p; p = p->next) {
        int v = p->val;
        Result childResult;
        childResult.dp0 = NULL;
        childResult.dp1 = NULL;
        childResult.size = 0;
        dfs(v, n, present, future, g, budget, &childResult, visited);

        uSize += childResult.size;
        for (int j = budget; j >= 0; j--) {
            for (int sub = 0; sub <= fmin(childResult.size, j); sub++) {
                if (j - sub >= 0) {
                    subProfit0[j] =
                        fmax(subProfit0[j],
                             subProfit0[j - sub] + childResult.dp0[sub]);
                    subProfit1[j] =
                        fmax(subProfit1[j],
                             subProfit1[j - sub] + childResult.dp1[sub]);
                }
            }
        }

        free(childResult.dp0);
        free(childResult.dp1);
    }

    for (int i = 0; i <= budget; i++) {
        dp0[i] = subProfit0[i];
        dp1[i] = subProfit0[i];
        if (i >= dCost) {
            dp1[i] =
                fmax(subProfit0[i], subProfit1[i - dCost] + future[u] - dCost);
        }
        if (i >= cost) {
            dp0[i] =
                fmax(subProfit0[i], subProfit1[i - cost] + future[u] - cost);
        }
    }

    result->dp0 = dp0;
    result->dp1 = dp1;
    result->size = uSize;

    free(subProfit0);
    free(subProfit1);
}

int maxProfit(int n, int* present, int presentSize, int* future, int futureSize,
              int** hierarchy, int hierarchySize, int* hierarchyColSize,
              int budget) {
    struct ListNode** g =
        (struct ListNode**)malloc(n * sizeof(struct ListNode*));
    for (int i = 0; i < n; i++) {
        g[i] = NULL;
    }
    for (int i = 0; i < hierarchySize; i++) {
        int u = hierarchy[i][0] - 1;
        int v = hierarchy[i][1] - 1;
        struct ListNode* p = creatListNode(v);
        p->next = g[u];
        g[u] = p;
    }

    int* visited = (int*)calloc(n, sizeof(int));
    Result result;
    result.dp0 = NULL;
    result.dp1 = NULL;
    result.size = 0;
    dfs(0, n, present, future, g, budget, &result, visited);

    int ret = result.dp0[budget];
    free(result.dp0);
    free(result.dp1);
    free(visited);
    for (int i = 0; i < n; i++) {
        freeList(g[i]);
    }
    free(g);

    return ret;
}