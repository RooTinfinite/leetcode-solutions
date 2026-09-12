typedef struct {
    int l, r, weight, idx;
} Interval;

int compareInterval(const void* a, const void* b) {
    return ((Interval*)a)->r - ((Interval*)b)->r;
}

int compareInt(const void* a, const void* b) { return (*(int*)a) - (*(int*)b); }

int binarySearch(Interval* arr, int end, int target) {
    int left = 0, right = end;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid].r < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int compareArrays(int* a, int lenA, int* b, int lenB) {
    int minLen = lenA < lenB ? lenA : lenB;
    for (int i = 0; i < minLen; i++) {
        if (a[i] != b[i]) {
            return a[i] - b[i];
        }
    }
    return lenA - lenB;
}

int* maximumWeight(int** intervals, int intervalsSize, int* intervalsColSize,
                   int* returnSize) {
    int n = intervalsSize;
    Interval* arr = (Interval*)malloc(n * sizeof(Interval));
    for (int i = 0; i < n; i++) {
        arr[i].l = intervals[i][0];
        arr[i].r = intervals[i][1];
        arr[i].weight = intervals[i][2];
        arr[i].idx = i;
    }
    // Sort by right endpoint.
    qsort(arr, n, sizeof(Interval), compareInterval);

    long long** dp = (long long**)malloc((n + 1) * sizeof(long long*));
    int*** indices = (int***)malloc((n + 1) * sizeof(int**));
    int** indicesSize = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (long long*)calloc(5, sizeof(long long));
        indices[i] = (int**)malloc(5 * sizeof(int*));
        indicesSize[i] = (int*)calloc(5, sizeof(int));
        for (int j = 0; j < 5; j++) {
            indices[i][j] = NULL;
        }
    }

    for (int i = 0; i < n; i++) {
        int l = arr[i].l, weight = arr[i].weight, idx = arr[i].idx;
        // Use binary search to find intervals whose right endpoints are smaller
        // than l.
        int k = binarySearch(arr, i, l);

        for (int j = 1; j < 5; j++) {
            long long s1 = dp[i][j];
            long long s2 = dp[k][j - 1] + weight;
            if (s1 > s2) {
                dp[i + 1][j] = dp[i][j];
                if (indices[i + 1][j]) free(indices[i + 1][j]);
                indices[i + 1][j] =
                    (int*)malloc(indicesSize[i][j] * sizeof(int));
                memcpy(indices[i + 1][j], indices[i][j],
                       indicesSize[i][j] * sizeof(int));
                indicesSize[i + 1][j] = indicesSize[i][j];
                continue;
            }

            int newSize = indicesSize[k][j - 1] + 1;
            int* newIndex = (int*)malloc(newSize * sizeof(int));
            if (indicesSize[k][j - 1] > 0) {
                memcpy(newIndex, indices[k][j - 1],
                       indicesSize[k][j - 1] * sizeof(int));
            }
            newIndex[indicesSize[k][j - 1]] = idx;
            qsort(newIndex, newSize, sizeof(int), compareInt);

            if (s1 == s2 && compareArrays(indices[i][j], indicesSize[i][j],
                                          newIndex, newSize) < 0) {
                free(newIndex);
                newIndex = (int*)malloc(indicesSize[i][j] * sizeof(int));
                memcpy(newIndex, indices[i][j],
                       indicesSize[i][j] * sizeof(int));
                newSize = indicesSize[i][j];
            }

            dp[i + 1][j] = s2;
            if (indices[i + 1][j]) {
                free(indices[i + 1][j]);
            }
            indices[i + 1][j] = newIndex;
            indicesSize[i + 1][j] = newSize;
        }
    }

    *returnSize = indicesSize[n][4];
    int* result = (int*)malloc(*returnSize * sizeof(int));
    memcpy(result, indices[n][4], *returnSize * sizeof(int));

    for (int i = 0; i <= n; i++) {
        free(dp[i]);
        for (int j = 0; j < 5; j++) {
            if (indices[i][j]) {
                free(indices[i][j]);
            }
        }
        free(indices[i]);
        free(indicesSize[i]);
    }
    free(dp);
    free(indices);
    free(indicesSize);
    free(arr);

    return result;
}