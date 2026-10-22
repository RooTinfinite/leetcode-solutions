static inline int min(int a, int b) { return a < b ? a : b; }

int minOperations(int* nums, int numsSize) {
    const int n = numsSize;
    if (n == 1) {
        return 0;
    }

    int start = 0;
    while (nums[start] != 0) {
        start++;
    }

    bool asc = true;
    bool desc = true;

    for (int i = 1; i < n; i++) {
        const int value = nums[(start + i) % n];

        if (value != i) {
            asc = false;
        }
        if (value != n - i) {
            desc = false;
        }

        if (!asc && !desc) {
            return -1;
        }
    }

    if (asc) {
        return min(start, n - start + 2);
    }

    return min(n - start, start + 2);
}