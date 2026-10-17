typedef struct {
    int digitSum;
    int value;
    int origIdx;
} Elem;

int cmp(const void* a, const void* b) {
    Elem* ea = (Elem*)a;
    Elem* eb = (Elem*)b;
    if (ea->digitSum != eb->digitSum) {
        return ea->digitSum - eb->digitSum;
    }
    return ea->value - eb->value;
}

int minSwaps(int* nums, int numsSize) {
    int n = numsSize;
    Elem* elems = (Elem*)malloc(n * sizeof(Elem));
    for (int i = 0; i < n; i++) {
        int x = nums[i], sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        elems[i].digitSum = sum;
        elems[i].value = nums[i];
        elems[i].origIdx = i;
    }
    qsort(elems, n, sizeof(Elem), cmp);

    int* targetPos = (int*)malloc(n * sizeof(int));
    for (int pos = 0; pos < n; pos++) {
        targetPos[elems[pos].origIdx] = pos;
    }

    bool* visited = (bool*)calloc(n, sizeof(bool));
    int cycles = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cycles++;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = targetPos[j];
            }
        }
    }

    free(elems);
    free(targetPos);
    free(visited);
    return n - cycles;
}