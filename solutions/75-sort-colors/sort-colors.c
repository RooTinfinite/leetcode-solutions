// Dutch National Flag problem solution.
void sortColors(int* nums, int numsSize) {
    // For all idx < p0 : nums[idx < p0] = 0
    // curr is an index of elements under consideration
    int p0 = 0, curr = 0;
    // For all idx > p2 : nums[idx > p2] = 2
    int p2 = numsSize - 1;
    while (curr <= p2) {
        if (nums[curr] == 0) {
            int temp = nums[p0];
            nums[p0++] = nums[curr];
            nums[curr++] = temp;
        } else if (nums[curr] == 2) {
            int temp = nums[curr];
            nums[curr] = nums[p2];
            nums[p2--] = temp;
        } else
            curr++;
    }
}