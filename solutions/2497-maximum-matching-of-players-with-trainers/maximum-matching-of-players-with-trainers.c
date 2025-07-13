int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int matchPlayersAndTrainers(int* players, int playersSize, int* trainers,
                            int trainersSize) {
    qsort(players, playersSize, sizeof(int), cmp);
    qsort(trainers, trainersSize, sizeof(int), cmp);
    int m = playersSize, n = trainersSize;
    int count = 0;
    for (int i = 0, j = 0; i < m && j < n; i++, j++) {
        while (j < n && players[i] > trainers[j]) {
            j++;
        }
        if (j < n) {
            count++;
        }
    }
    return count;
}