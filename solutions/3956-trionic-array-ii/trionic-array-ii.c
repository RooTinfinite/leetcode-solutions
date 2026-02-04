#include <stdio.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long maxSumTrionic(int* nums, int numsSize) {
    long long res = -1e16;
    for (int i = 1; i < numsSize - 2; ) {
        int a = i, b = i;
        long long net = nums[a];

        while (b + 1 < numsSize && nums[b + 1] < nums[b]) {
            net += nums[++b];
        }
        if (b == a) { i++; continue; }

        int c = b;
        long long left = 0, right = 0, lx = -1e16, rx = -1e16;

        while (a - 1 >= 0 && nums[a - 1] < nums[a]) {
            left += nums[--a];
            lx = MAX(lx, left);
        }
        if (a == i) { i++; continue; }

        while (b + 1 < numsSize && nums[b + 1] > nums[b]) {
            right += nums[++b];
            rx = MAX(rx, right);
        }
        if (b == c) { i++; continue; }

        res = MAX(res, lx + rx + net);
        i = b;
    }
    return res;
}