class Solution {
    public long[] mostFrequentIDs(int[] nums, int[] freq) {
        int n = nums.length; 
        Map<Long, Long> cnt = new HashMap(); 
        Queue<long[]> pq = new PriorityQueue<>((x, y) -> Long.compare(y[0], x[0])); 
        long[] ans = new long[n]; 
        for (int i = 0; i < n; ++i) {
            long x = nums[i], f = freq[i]; 
            cnt.merge(x, f, Long::sum); 
            while (!pq.isEmpty() && cnt.get(pq.peek()[1]) != pq.peek()[0]) pq.poll(); 
            pq.add(new long[]{cnt.get(x), x}); 
            ans[i] = pq.peek()[0]; 
        }
        return ans; 
    }
}