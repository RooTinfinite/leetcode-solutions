public class Solution {
    public int FindMin(int[] nums) {
        int low = 0, high = nums.Length - 1;

        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high])
                high = pivot;
            else if (nums[pivot] > nums[high])
                low = pivot + 1;
            else
                high -= 1;
        }

        return nums[low];
    }
}