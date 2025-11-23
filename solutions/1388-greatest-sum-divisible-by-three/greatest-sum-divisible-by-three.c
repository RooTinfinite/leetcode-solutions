static int cmp(const void* a, const void* b) { return *(int*)b - *(int*)a; }

int maxSumDivThree(int* nums, int numsSize) {
    // Use v[0], v[1], v[2] to represent a, b, c respectively.
    int n = numsSize;
    int v[3][n];
    int vColSize[3];
    memset(vColSize, 0, sizeof(vColSize));
    for (int i = 0; i < numsSize; i++) {
        v[nums[i] % 3][vColSize[nums[i] % 3]++] = nums[i];
    }
    qsort(v[1], vColSize[1], sizeof(int), cmp);
    qsort(v[2], vColSize[2], sizeof(int), cmp);
    int tot = 0, remove = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        tot += nums[i];
    }

    if (tot % 3 == 0) {
        remove = 0;
    } else if (tot % 3 == 1) {
        if (vColSize[1] >= 1) {
            remove = fmin(remove, v[1][vColSize[1] - 1]);
        }
        if (vColSize[2] >= 2) {
            remove =
                fmin(remove, v[2][vColSize[2] - 2] + v[2][vColSize[2] - 1]);
        }
    } else {
        if (vColSize[1] >= 2) {
            remove =
                fmin(remove, v[1][vColSize[1] - 2] + v[1][vColSize[1] - 1]);
        }
        if (vColSize[2] >= 1) {
            remove = fmin(remove, v[2][vColSize[2] - 1]);
        }
    }

    return tot - remove;
}