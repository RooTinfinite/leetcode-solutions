typedef struct {
    int* tree;
    int n;
} BIT;

static int lowbit(int x) { return x & -x; }

static void bit_init(BIT* b, int n) {
    b->n = n;
    b->tree = (int*)calloc(n + 1, sizeof(int));
}

static void bit_update(BIT* b, int x, int v) {
    while (x <= b->n) {
        b->tree[x] ^= v;
        x += lowbit(x);
    }
}

static int bit_query(BIT* b, int x) {
    int ret = 0;
    while (x > 0) {
        ret ^= b->tree[x];
        x -= lowbit(x);
    }
    return ret;
}

static void bit_update_range(BIT* b, int l, int r, int v) {
    bit_update(b, l, v);
    bit_update(b, r + 1, v);
}

static int popcount(unsigned int x) {
    int c = 0;
    while (x) {
        c += x & 1;
        x >>= 1;
    }
    return c;
}

typedef struct {
    int* head;
    int* to;
    int* next;
    int edge_cnt;
} Graph;

static void graph_init(Graph* gr, int n, int max_edges) {
    gr->head = (int*)malloc(n * sizeof(int));
    gr->to = (int*)malloc(max_edges * sizeof(int));
    gr->next = (int*)malloc(max_edges * sizeof(int));
    gr->edge_cnt = 0;
    for (int i = 0; i < n; i++) {
        gr->head[i] = -1;
    }
}

static void graph_add(Graph* gr, int u, int v) {
    gr->to[gr->edge_cnt] = v;
    gr->next[gr->edge_cnt] = gr->head[u];
    gr->head[u] = gr->edge_cnt++;
}

static void graph_free(Graph* gr) {
    free(gr->head);
    free(gr->to);
    free(gr->next);
}

static void dfs(int u, int p, Graph* gr, int** fa, int* dep, int* l, int* r,
                int* timer) {
    (*timer)++;
    l[u] = *timer;
    fa[u][0] = p;

    for (int idx = gr->head[u]; idx != -1; idx = gr->next[idx]) {
        int v = gr->to[idx];
        if (v == p) {
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u, gr, fa, dep, l, r, timer);
    }

    r[u] = *timer;
}

static int lca(int u, int v, int* dep, int** fa, int LOG) {
    if (dep[u] < dep[v]) {
        int t = u;
        u = v;
        v = t;
    }
    int diff = dep[u] - dep[v];
    for (int i = 0; i < LOG; i++) {
        if ((diff >> i) & 1) {
            u = fa[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

bool* palindromePath(int n, int** edges, int edgesSize, int* edgesColSize,
                     char* s, char** queries, int queriesSize,
                     int* returnSize) {
    Graph gr;
    graph_init(&gr, n, 2 * edgesSize + 1);
    for (int i = 0; i < edgesSize; i++) {
        graph_add(&gr, edges[i][0], edges[i][1]);
        graph_add(&gr, edges[i][1], edges[i][0]);
    }

    int LOG = 1;
    while ((1 << LOG) <= n) {
        LOG++;
    }

    int** fa = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        fa[i] = (int*)calloc(LOG, sizeof(int));
    }
    int* dep = (int*)calloc(n, sizeof(int));
    int* l = (int*)calloc(n, sizeof(int));
    int* r = (int*)calloc(n, sizeof(int));
    int timer = 0;

    dfs(0, 0, &gr, fa, dep, l, r, &timer);

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }

    BIT bit;
    bit_init(&bit, n + 1);
    for (int i = 0; i < n; i++) {
        bit_update_range(&bit, l[i], r[i], 1 << (s[i] - 'a'));
    }

    bool* ans = (bool*)malloc(queriesSize * sizeof(bool));
    int ansSize = 0;
    for (int qi = 0; qi < queriesSize; qi++) {
        char* q = queries[qi];
        char* p = q;
        while (*p == ' ') {
            p++;
        }
        if (*p == 'u') {
            int u;
            char c;
            sscanf(p, "update %d %c", &u, &c);
            bit_update_range(&bit, l[u], r[u],
                             (1 << (s[u] - 'a')) ^ (1 << (c - 'a')));
            s[u] = c;
        } else {
            int u, v;
            sscanf(p, "query %d %d", &u, &v);
            int w = lca(u, v, dep, fa, LOG);
            int mask = bit_query(&bit, l[u]) ^ bit_query(&bit, l[v]) ^
                       (1 << (s[w] - 'a'));
            ans[ansSize++] = popcount((unsigned int)mask) <= 1;
        }
    }

    for (int i = 0; i < n; i++) {
        free(fa[i]);
    }
    free(fa);
    free(dep);
    free(l);
    free(r);
    free(bit.tree);
    graph_free(&gr);

    *returnSize = ansSize;
    return ans;
}