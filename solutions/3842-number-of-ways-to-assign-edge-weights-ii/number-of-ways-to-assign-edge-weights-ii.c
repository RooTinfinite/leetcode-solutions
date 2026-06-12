#define MOD 1000000007
#define N 100010

typedef struct {
    int n;
    int m;
    int* d;
    int** e;
    int* e_size;
    int* e_cap;
    int** f;
} LCA;

int p2[N];

void init_p2() {
    p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p2[i] = (int)((long long)p2[i - 1] * 2 % MOD);
    }
}

void add_edge(LCA* lca, int u, int v) {
    if (lca->e_size[u] >= lca->e_cap[u]) {
        lca->e_cap[u] *= 2;
        lca->e[u] = (int*)realloc(lca->e[u], lca->e_cap[u] * sizeof(int));
    }
    lca->e[u][lca->e_size[u]++] = v;
}

void dfs(LCA* lca, int x, int fa) {
    lca->f[x][0] = fa;
    for (int i = 0; i < lca->e_size[x]; i++) {
        int y = lca->e[x][i];
        if (y == fa) {
            continue;
        }
        lca->d[y] = lca->d[x] + 1;
        dfs(lca, y, x);
    }
}

LCA* create_lca(int** edges, int edges_size, int root) {
    LCA* lca = (LCA*)malloc(sizeof(LCA));
    lca->n = edges_size + 1;
    lca->m = (int)(log(lca->n) / log(2)) + 1;

    lca->d = (int*)calloc(lca->n + 1, sizeof(int));
    lca->e = (int**)malloc((lca->n + 1) * sizeof(int*));
    lca->e_size = (int*)calloc(lca->n + 1, sizeof(int));
    lca->e_cap = (int*)malloc((lca->n + 1) * sizeof(int));
    lca->f = (int**)malloc((lca->n + 1) * sizeof(int*));

    for (int i = 0; i <= lca->n; i++) {
        lca->e[i] = (int*)malloc(10 * sizeof(int));
        lca->e_cap[i] = 10;
        lca->f[i] = (int*)calloc(lca->m, sizeof(int));
    }

    for (int i = 0; i < edges_size; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        add_edge(lca, u, v);
        add_edge(lca, v, u);
    }

    dfs(lca, root, 0);

    for (int i = 1; i < lca->m; i++) {
        for (int x = 1; x <= lca->n; x++) {
            lca->f[x][i] = lca->f[lca->f[x][i - 1]][i - 1];
        }
    }

    return lca;
}

int lca_query(LCA* lca, int x, int y) {
    if (lca->d[x] > lca->d[y]) {
        int temp = x;
        x = y;
        y = temp;
    }

    for (int i = lca->m - 1; i >= 0; i--) {
        if (lca->d[x] <= lca->d[lca->f[y][i]]) {
            y = lca->f[y][i];
        }
    }

    if (x == y) {
        return x;
    }

    for (int i = lca->m - 1; i >= 0; i--) {
        if (lca->f[y][i] != lca->f[x][i]) {
            x = lca->f[x][i];
            y = lca->f[y][i];
        }
    }

    return lca->f[x][0];
}

int dis(LCA* lca, int x, int y) {
    return lca->d[x] + lca->d[y] - lca->d[lca_query(lca, x, y)] * 2;
}

void free_lca(LCA* lca) {
    for (int i = 0; i <= lca->n; i++) {
        free(lca->e[i]);
        free(lca->f[i]);
    }
    free(lca->d);
    free(lca->e);
    free(lca->e_size);
    free(lca->e_cap);
    free(lca->f);
    free(lca);
}

int* assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize,
                       int** queries, int queriesSize, int* queriesColSize,
                       int* returnSize) {
    init_p2();
    LCA* lca = create_lca(edges, edgesSize, 1);
    *returnSize = queriesSize;
    int* res = (int*)calloc(queriesSize, sizeof(int));

    for (int i = 0; i < queriesSize; i++) {
        int x = queries[i][0];
        int y = queries[i][1];
        if (x != y) {
            res[i] = p2[dis(lca, x, y) - 1];
        }
    }

    free_lca(lca);
    return res;
}