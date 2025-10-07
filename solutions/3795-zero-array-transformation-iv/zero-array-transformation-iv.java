import java.util.*;

class Solution {
    public int minZeroArray(int[] nums, int[][] queries) {
        return minOperations(nums, queries);
    }

    public int minOperations(int[] nums, int[][] queries) {
        int left = 0, right = queries.length, answer = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canMakeZero(nums, queries, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }

    private boolean canMakeZero(int[] nums, int[][] queries, int k) {
        int n = nums.length;
        Map<Integer, List<Integer>> map = new HashMap<>();

        // Initialize map for each index
        for (int i = 0; i < n; i++) {
            map.put(i, new ArrayList<>());
        }

        // Apply first k queries
        for (int i = 0; i < k; i++) {
            int left = queries[i][0];
            int ri = queries[i][1];
            int vali = queries[i][2];
            for (int j = left; j <= ri; j++) {
                map.get(j).add(vali);
            }
        }

        // Check if each index can be made zero using subset sum
        for (int i = 0; i < n; i++) {
            int target = nums[i];
            List<Integer> values = map.get(i);

            if (!subop(values, target)) {
                return false;
            }
        }
        return true;
    }

    private boolean subop(List<Integer> values, int target) {
        int size = values.size();
        if (target == 0) return true;
        if (size == 0) return false;

        // Subset Sum DP: Check if we can form `target`
        boolean[] dp = new boolean[target + 1];
        dp[0] = true;

        for (int num : values) {
            for (int j = target; j >= num; j--) {
                dp[j] |= dp[j - num];
            }
        }
        return dp[target];
    }
}