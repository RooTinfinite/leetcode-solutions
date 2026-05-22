int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Case 1: find target
        if (nums[mid] == target) return mid;
        // Case 2: Subarray on mid's left is sorted
        else if (nums[mid] >= nums[left]) {
            if (target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        // Case 3: Subarray on mid's right is sorted
        else {
            if (target <= nums[right] && target > nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}