public class Solution {
    public long CountNonDecreasingSubarrays(int[] nums, int k) {
        int n = nums.Length;
        long ans = 0;
        long operations = 0;
        // Maintain the window maximum with a priority queue
        var q = new PriorityQueue<(int val, int idx), int>();
        // Record the set of elements covered by this index
        var cnt = new List<int>[n];
        for (int i = 0; i < n; i++) {
            cnt[i] = new List<int>();
        }
        // Index of the first greater-or-equal element to the right
        var pos = new int[n];
        Array.Fill(pos, n);
        // Decreasing monotonic stack
        var st = new Stack<int>();

        for (int left = 0, right = 0; right < n; right++) {
            // Maintain the monotonic stack
            while (st.Count > 0 && nums[right] >= nums[st.Peek()]) {
                pos[st.Peek()] = right;
                st.Pop();
            }
            // The stack top is the nearest greater element to the left of
            // nums[right]
            if (st.Count > 0) {
                cnt[st.Peek()].Add(right);
            }
            st.Push(right);

            // The priority queue front is the window maximum
            q.Enqueue((nums[right], right), -nums[right]);
            // Adding nums[right] increases the operation count
            operations += Math.Max(0, q.Peek().val - nums[right]);

            // The minimum operation count exceeds k; shrink the window
            while (operations > k) {
                // Removing nums[left] from the window decreases the operation
                // count
                foreach (int i in cnt[left]) {
                    // Subtract the contribution
                    operations -= (long)(nums[left] - nums[i]) *
                                  (Math.Min(pos[i], right + 1) - i);
                }
                left++;
            }

            // Remove elements with indices less than left from the priority
            // queue
            while (q.Count > 0 && q.Peek().idx < left) {
                q.Dequeue();
            }

            // There are right - left + 1 valid contiguous subarrays ending at
            // right
            ans += right - left + 1;
        }

        return ans;
    }
}