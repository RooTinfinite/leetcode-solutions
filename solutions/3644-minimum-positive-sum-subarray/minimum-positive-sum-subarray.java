class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int minSum = Integer.MAX_VALUE;
        for (int start = l; start <= r; start++) {
            int sum = 0;
            for (int i = 0; i < start && i < nums.size(); i++) {
                sum += nums.get(i);
            }
            if (sum > 0) {
                minSum = Math.min(minSum, sum);
            }
            for (int end = start; end < nums.size(); end++) {
                sum += nums.get(end) - nums.get(end - start);
                if (sum > 0) {
                    minSum = Math.min(minSum, sum);
                }
            }
        }
        return minSum == Integer.MAX_VALUE ? -1 : minSum;
    }
}