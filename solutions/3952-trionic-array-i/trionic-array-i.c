bool isTrionic(int* nums, int numsSize) {
    int n = numsSize, i = 1;
    while (i < n && nums[i - 1] < nums[i]) {
        i++;
    }
    int p = i - 1;
    while (i < n && nums[i - 1] > nums[i]) {
        i++;
    }
    int q = i - 1;
    while (i < n && nums[i - 1] < nums[i]) {
        i++;
    }
    int flag = i - 1;
    return (p != 0) && (q != p) && (flag == n - 1 && flag != q);
}