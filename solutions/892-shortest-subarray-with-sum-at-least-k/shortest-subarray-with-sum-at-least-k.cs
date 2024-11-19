public class Solution {
    public int ShortestSubarray(int[] nums, int k) {
        int res = int.MaxValue;
        long curSum = 0;
        var minHeap = new PriorityQueue<(long sum, int idx), long>();
        
        for (int r = 0; r < nums.Length; r++) {
            curSum += nums[r];
            
            if (curSum >= k) {
                res = Math.Min(res, r + 1);
            }
            
            while (minHeap.Count > 0 && curSum - minHeap.Peek().sum >= k) {
                var (prefixSum, endIdx) = minHeap.Dequeue();
                res = Math.Min(res, r - endIdx);
            }
            
            minHeap.Enqueue((curSum, r), curSum);
        }
        
        return res == int.MaxValue ? -1 : res;
    }
}