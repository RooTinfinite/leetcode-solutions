#define MOD 1000000007

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node** heads;
    int size;
} Graph;

void addEdge(Graph* g, int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = v;
    node->next = g->heads[u];
    g->heads[u] = node;
}

int qpow(int x, int y) {
    long long res = 1;
    long long base = x;
    while (y) {
        if (y & 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        y >>= 1;
    }
    return (int)res;
}

int dfs(Graph* g, int x, int f) {
    int maxDep = 0;
    Node* cur = g->heads[x];
    while (cur) {
        int y = cur->val;
        if (y != f) {
            int dep = dfs(g, y, x) + 1;
            if (dep > maxDep) maxDep = dep;
        }
        cur = cur->next;
    }
    return maxDep;
}

int assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize) {
    int n = edgesSize + 1;
    Graph g;
    g.heads = (Node**)calloc(n + 1, sizeof(Node*));
    g.size = n + 1;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        addEdge(&g, u, v);
        addEdge(&g, v, u);
    }

    int maxDep = dfs(&g, 1, 0);
    int result = qpow(2, maxDep - 1);

    for (int i = 0; i <= n; i++) {
        Node* cur = g.heads[i];
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(g.heads);

    return result;
}