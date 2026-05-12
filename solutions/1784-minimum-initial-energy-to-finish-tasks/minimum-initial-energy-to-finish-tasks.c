int compareDesc(const void* a, const void* b) {
    int* taskA = *(int**)a;
    int* taskB = *(int**)b;
    return (taskB[1] - taskB[0]) - (taskA[1] - taskA[0]);
}

int maxInt(int a, int b) { return a > b ? a : b; }

int minimumEffort(int** tasks, int tasksSize, int* tasksColSize) {
    qsort(tasks, tasksSize, sizeof(int*), compareDesc);
    int ans = 0;
    int remain = 0;
    for (int i = 0; i < tasksSize; i++) {
        int task0 = tasks[i][0];
        int task1 = tasks[i][1];
        if (remain <= task1) {
            ans += task1 - remain;
        }
        remain = maxInt(task1 - task0, remain - task0);
    }
    return ans;
}