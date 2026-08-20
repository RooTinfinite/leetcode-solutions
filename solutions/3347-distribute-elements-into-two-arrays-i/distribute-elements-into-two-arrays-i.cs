public class Solution {
    public int[] ResultArray(int[] nums) {
        int n = nums.Length;
        int[] arr = new int[n];
        arr[0] = nums[0];
        arr[n - 1] = nums[1];
        int idx = 0, revIdx = n - 1;
        for (int i = 2; i < n; i++) {
            if (arr[idx] > arr[revIdx]) {
                arr[++idx] = nums[i];
            } else {
                arr[--revIdx] = nums[i];
            }
        }
        Array.Reverse(arr, revIdx, n - revIdx);
        return arr;
    }
}