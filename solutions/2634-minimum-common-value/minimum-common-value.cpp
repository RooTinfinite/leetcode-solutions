class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Binary search should be done on the larger array
        // If nums1 is longer, call getCommon with the arrays swapped
        if (nums1.size() > nums2.size()) {
            return getCommon(nums2, nums1);
        }

        // Search for each element of nums1 in nums2
        // Return the first common element found
        for (int num : nums1) {
            if (binarySearch(num, nums2)) {
                return num;
            }
        }

        // Return -1 if there are no common elements
        return -1;
    }

private:
    bool binarySearch(int target, vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};