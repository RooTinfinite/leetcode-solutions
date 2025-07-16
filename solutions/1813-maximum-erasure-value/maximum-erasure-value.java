class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> lastIndexMap = new HashMap<>();
        int[] prefixSum = new int[n + 1];

        int result = 0, start = 0;
        for (int end = 0; end < n; end++) {
            int currentElement = nums[end];
            prefixSum[end + 1] = prefixSum[end] + currentElement;
            if (lastIndexMap.containsKey(currentElement)) {
                start = Math.max(start, lastIndexMap.get(currentElement) + 1);
            }
            // update result with maximum sum found so far
            result = Math.max(result, prefixSum[end + 1] - prefixSum[start]);
            lastIndexMap.put(currentElement, end);
        }
        return result;
    }
}