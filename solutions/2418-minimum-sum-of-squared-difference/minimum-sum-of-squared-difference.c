int cmpDesc(const void* a, const void* b) {
    return *(const int*)b - *(const int*)a;
}

long long minSumSquareDiff(int* nums1, int nums1Size, int* nums2, int nums2Size,
                           int k1, int k2) {
    int n = nums1Size;
    int k = k1 + k2;
    int maxDif = 0;
    for (int i = 0; i < n; i++) {
        nums1[i] = abs(nums1[i] - nums2[i]);
        if (nums1[i] > maxDif) {
            maxDif = nums1[i];
        }
    }

    int l = 0, r = maxDif, res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums1[i] > mid ? nums1[i] - mid : 0;
        }
        if (sum <= k) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums1[i] > res) {
            k -= nums1[i] - res;
        }
    }

    qsort(nums1, n, sizeof(int), cmpDesc);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long diff = nums1[i] < res ? nums1[i] : res;
        if (k > 0 && diff > 0) {
            diff--;
            k--;
        }
        ans += diff * diff;
    }
    return ans;
}