class Solution {
    public long countRatioSubarrays(int[] nums, int a, int b) {
        int n = nums.length;

        long[] evenPrefix = new long[n + 1];
        long[] oddPrefix = new long[n + 1];

        for (int i = 1; i <= n; i++) {
            evenPrefix[i] = evenPrefix[i - 1];
            oddPrefix[i] = oddPrefix[i - 1];

            if ((nums[i - 1] & 1) == 0) {
                evenPrefix[i]++;
            } else {
                oddPrefix[i]++;
            }
        }

        long[] prefixValue = new long[n + 1];
        for (int i = 0; i <= n; i++) {
            prefixValue[i] = (long) b * evenPrefix[i] - (long) a * oddPrefix[i];
        }

        long[] sortedValues = prefixValue.clone();
        Arrays.sort(sortedValues);

        long[] uniqueValues = new long[n + 1];
        int uniqueCount = 0;

        for (long value : sortedValues) {
            if (uniqueCount == 0 || uniqueValues[uniqueCount - 1] != value) {
                uniqueValues[uniqueCount++] = value;
            }
        }

        int[] fenwick = new int[uniqueCount + 1];

        long res = 0;
        int leftPointer = 0;

        for (int right = 0; right <= n; right++) {
            while (leftPointer < right && oddPrefix[leftPointer] < oddPrefix[right]) {
                int rank = Arrays.binarySearch(uniqueValues, 0, uniqueCount, prefixValue[leftPointer]) + 1;

                updateFenwick(fenwick, uniqueCount, rank, 1);
                leftPointer++;
            }

            int currentRank = Arrays.binarySearch(uniqueValues, 0, uniqueCount, prefixValue[right]) + 1;

            int smallerCount = queryFenwick(fenwick, currentRank - 1);

            res += (long) leftPointer - smallerCount;
        }

        return res;
    }

    private void updateFenwick(int[] fenwick, int size, int index, int value) {
        while (index <= size) {
            fenwick[index] += value;
            index += index & -index;
        }
    }

    private int queryFenwick(int[] fenwick, int index) {
        int sum = 0;

        while (index > 0) {
            sum += fenwick[index];
            index -= index & -index;
        }

        return sum;
    }
}