int compare(const void* a, const void* b) { return (*(int*)b - *(int*)a); }

int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int sum = 0;
    for (int i = 0; i < appleSize; i++) {
        sum += apple[i];
    }

    qsort(capacity, capacitySize, sizeof(int), compare);
    int need = 0;
    while (sum > 0) {
        sum -= capacity[need];
        need += 1;
    }

    return need;
}