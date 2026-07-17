int* gcdValues(int* nums, int numsSize, long long* queries, int queriesSize,
               int* returnSize) {
    int m = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > m) {
            m = nums[i];
        }
    }
    long long* cnt = (long long*)calloc(m + 1, sizeof(long long));
    for (int i = 0; i < numsSize; i++) {
        cnt[nums[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i * 2; j <= m; j += i) {
            cnt[i] += cnt[j];
        }
    }
    for (int i = 1; i <= m; i++) {
        cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
    }
    for (int i = m; i >= 1; i--) {
        for (int j = i * 2; j <= m; j += i) {
            cnt[i] -= cnt[j];
        }
    }
    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }
    int* ans = (int*)malloc(queriesSize * sizeof(int));
    for (int k = 0; k < queriesSize; k++) {
        long long q = queries[k] + 1;
        int left = 1, right = m;
        while (left < right) {
            int mid = (left + right) / 2;
            if (cnt[mid] >= q) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans[k] = left;
    }
    free(cnt);
    *returnSize = queriesSize;
    return ans;
}