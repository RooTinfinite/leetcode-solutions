#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

double minimumAverage(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int left = 0, right = numsSize - 1;
    double minAvg = DBL_MAX;

    while (left < right) {
        double avg = (nums[left] + nums[right]) / 2.0;
        if (avg < minAvg) minAvg = avg;
        left++;
        right--;
    }
    return minAvg;
}