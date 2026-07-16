int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

long long gcdSum(int* nums, int numsSize) {
    int* mx = (int*)malloc(numsSize * sizeof(int));
    int prefixMax = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > prefixMax) prefixMax = nums[i];
        mx[i] = prefixMax;
    }

    int* prefixGcd = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        prefixGcd[i] = gcd(nums[i], mx[i]);
    }

    qsort(prefixGcd, numsSize, sizeof(int), cmp);
    long long ans = 0;
    int left = 0, right = numsSize - 1;
    while (left < right) {
        ans += gcd(prefixGcd[left], prefixGcd[right]);
        left++;
        right--;
    }

    free(mx);
    free(prefixGcd);
    return ans;
}