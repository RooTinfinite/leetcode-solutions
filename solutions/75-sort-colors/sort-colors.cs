public class Solution {
    /*
    Dutch National Flag problem solution.
    */
    public void SortColors(int[] nums) {
        // For all idx < i : nums[idx < i] = 0
        // j is an index of elements under consideration
        var p0 = 0;
        var curr = 0;
        // For all idx > k : nums[idx > k] = 2
        var p2 = nums.Length - 1;
        while (curr <= p2) {
            if (nums[curr] == 0) {
                // Swap p0-th and curr-th elements
                // i++ and j++
                int temp = nums[p0];
                nums[p0++] = nums[curr];
                nums[curr++] = temp;
            } else if (nums[curr] == 2) {
                // Swap k-th and curr-th elements
                // p2--
                int temp = nums[curr];
                nums[curr] = nums[p2];
                nums[p2--] = temp;
            } else
                curr++;
        }
    }
}