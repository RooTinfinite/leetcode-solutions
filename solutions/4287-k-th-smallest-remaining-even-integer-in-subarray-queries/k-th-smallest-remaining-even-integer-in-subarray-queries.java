import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] kthRemainingInteger(int[] nums, int[][] queries) {

        // STEP 1: Store all even numbers with their original indexes.
        List<int[]> evenNumbers = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] % 2 == 0) {
                evenNumbers.add(new int[]{nums[i], i});
            }
        }

        // STEP 2: Process each query independently.
        int[] result = new int[queries.length];
        int i = 0;

        for (int[] query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];

            // Find first even number whose index >= l
            int leftIndex = 0, rightIndex = evenNumbers.size();

            while (leftIndex < rightIndex) {
                int mid = leftIndex + (rightIndex - leftIndex) / 2;

                if (evenNumbers.get(mid)[1] < l) {
                    leftIndex = mid + 1;
                } else {
                    rightIndex = mid;
                }
            }

            int start = leftIndex;

            // Find first even number whose index > r
            leftIndex = 0;
            rightIndex = evenNumbers.size();

            while (leftIndex < rightIndex) {
                int mid = leftIndex + (rightIndex - leftIndex) / 2;

                if (evenNumbers.get(mid)[1] <= r) {
                    leftIndex = mid + 1;
                } else {
                    rightIndex = mid;
                }
            }

            int end = leftIndex;

            // STEP 3: Binary search the kth remaining even number.
            long lo = 2;
            long hi = (long) 2 * (k + nums.length + 5);

            int ans = 2;

            while (lo <= hi) {
                long mid = lo + (hi - lo) / 2;

                // Only even numbers are valid answers
                if (mid % 2 == 1) mid--;

                if (isValid(evenNumbers, start, end, mid, k)) {
                    ans = (int) mid;
                    hi = mid - 2;
                } else {
                    lo = mid + 2;
                }
            }

            result[i++] = ans;
        }

        return result;
    }

    private boolean isValid(List<int[]> evenNumbers, int start, int end, long x, int k) {

        // Removed even numbers <= x inside current query range
        int removed = upperBoundValue(evenNumbers, start, end, x) - start;

        long totalEven = x / 2;
        long remaining = totalEven - removed;

        return remaining >= k;
    }

    // First position with value > x in [start, end)
    private int upperBoundValue(List<int[]> arr, int start, int end, long x) {

        int l = start, r = end;

        while (l < r) {
            int mid = (l + r) / 2;

            if (arr.get(mid)[0] <= x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
}