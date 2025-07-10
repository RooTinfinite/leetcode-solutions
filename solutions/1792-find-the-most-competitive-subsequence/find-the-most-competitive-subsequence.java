class Solution {
    public int[] mostCompetitive(int[] nums, int k) {
        Deque<Integer> queue = new ArrayDeque<Integer>();
        int additionalCount = nums.length - k;
        for (int i = 0; i < nums.length; i++) {
            while (!queue.isEmpty() && queue.peekLast() > nums[i] && additionalCount > 0) {
                queue.pollLast();
                additionalCount--;
            }
            queue.addLast(nums[i]);
        }
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = queue.pollFirst();
        }
        return result;
    }
}