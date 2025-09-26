import java.util.Arrays;

public class Solution {

    public static int minimumArrayLength(int[] nums) {

        // Sorting the array in ascending order
        Arrays.sort(nums);

        // Checking if there are more than two elements and the second element is different from the first
        if (nums.length > 2 && nums[1] != nums[0]) {
            // If true, returning 1
            return 1;
        }

        // Initializing the highest common factor with the first element
        int h = nums[0];

        // Calculating the highest common factor of all elements in the array
        for (int i : nums) {
            h = hcf(h, i);
        }

        // Counting the occurrences of the highest common factor in the array
        int count = 0;
        for (int i : nums) {
            if (i == h) {
                count++;
            }
        }

        // If there are more than one occurrences, returning half of the count
        if (count > 1) {
            return (count + 1) / 2;
        }

        // Otherwise, returning 1
        return 1;
    }

    // Helper method to calculate the highest common factor
    static int hcf(int a, int b) {
        return b == 0 ? a : hcf(b, a % b);
    }
}