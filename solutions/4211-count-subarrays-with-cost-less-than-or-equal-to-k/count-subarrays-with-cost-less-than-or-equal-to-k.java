class Solution {
    public long countSubarrays(int[] nums, long k) {
        int n = nums.length;

        ArrayDeque<Integer> maxq = new ArrayDeque<>(); // indices
        ArrayDeque<Integer> minq = new ArrayDeque<>();

        long res = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            while (!maxq.isEmpty() && nums[maxq.peekLast()] <= nums[r]) 
                maxq.pollLast();
            maxq.addLast(r);

            while (!minq.isEmpty() && nums[minq.peekLast()] >= nums[r]) 
                minq.pollLast();
            minq.addLast(r);

            while (l <= r && (long)(r - l + 1) * ((long)nums[maxq.peekFirst()] - (long)nums[minq.peekFirst()]) > k) {
                if (!maxq.isEmpty() && maxq.peekFirst() == l) 
                    maxq.pollFirst();
                if (!minq.isEmpty() && minq.peekFirst() == l) 
                    minq.pollFirst();
                l++;
            }

            res += (r - l + 1);
        }

        return res;
    }
}