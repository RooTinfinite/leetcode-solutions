int compareDesc(const void* a, const void* b) { return *(int*)b - *(int*)a; }

int minimumCost(int* cost, int costSize) {
    qsort(cost, costSize, sizeof(int), compareDesc);
    int res = 0;
    for (int i = 0; i < costSize; ++i) {
        if (i % 3 != 2) {
            res += cost[i];
        }
    }
    return res;
}