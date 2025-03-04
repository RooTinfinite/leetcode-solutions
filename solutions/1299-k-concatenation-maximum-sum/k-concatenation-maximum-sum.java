class Solution {
 private static final int MOD = 1000000007;

    public int kConcatenationMaxSum(int[] arr, int k) {
        long sum = 0;
        long maxSum = 0;
        long currSum = 0;
        int n = arr.length;

        for (int num : arr) {
            sum += num;
            currSum = Math.max(num, currSum + num);
            maxSum = Math.max(maxSum, currSum);
        }

        if (k == 1) return (int) (maxSum % MOD);

        for (int num : arr) {
            currSum = Math.max(num, currSum + num);
            maxSum = Math.max(maxSum, currSum);
        }

        if (sum <= 0) return (int) (maxSum % MOD);

        return (int) ((maxSum + (k - 2) * sum) % MOD);
    }
}