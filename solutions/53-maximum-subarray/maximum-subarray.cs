public class Solution {
    private int[] numsArray;

    public int MaxSubArray(int[] nums) {
        numsArray = nums;
        // Our helper function is designed to solve this problem for
        // any array - so just call it using the entire input!
        return FindBestSubarray(0, numsArray.Length - 1);
    }

    private int FindBestSubarray(int left, int right) {
        // Base case - empty array.
        if (left > right) {
            return Int32.MinValue;
        }

        int mid = (left + right) / 2;
        int curr = 0;
        int bestLeftSum = 0;
        int bestRightSum = 0;
        // Iterate from the middle to the beginning.
        for (int i = mid - 1; i >= left; i--) {
            curr += numsArray[i];
            bestLeftSum = Math.Max(bestLeftSum, curr);
        }

        // Reset curr and iterate from the middle to the end.
        curr = 0;
        for (int i = mid + 1; i <= right; i++) {
            curr += numsArray[i];
            bestRightSum = Math.Max(bestRightSum, curr);
        }

        // The bestCombinedSum uses the middle element and the best possible sum
        // from each half.
        int bestCombinedSum = numsArray[mid] + bestLeftSum + bestRightSum;
        // Find the best subarray possible from both halves.
        int leftHalf = FindBestSubarray(left, mid - 1);
        int rightHalf = FindBestSubarray(mid + 1, right);
        // The largest of the 3 is the answer for any given input array.
        return Math.Max(bestCombinedSum, Math.Max(leftHalf, rightHalf));
    }
}