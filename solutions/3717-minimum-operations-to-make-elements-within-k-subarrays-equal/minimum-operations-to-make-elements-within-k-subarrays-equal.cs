public class Solution {
    private long[] GetCosts(int[] nums, int x) {
        int n = nums.Length;
        long[] ops = new long[n];
        SortedSet<(int Value, int Index)> left =
            new SortedSet<(int Value, int Index)>();
        SortedSet<(int Value, int Index)> right =
            new SortedSet<(int Value, int Index)>();
        long sumL = 0, sumR = 0;

        for (int i = 0; i < n; ++i) {
            var item = (Value: nums[i], Index: i);
            if (left.Count == 0 || item.Value <= left.Max.Value) {
                left.Add(item);
                sumL += item.Value;
            } else {
                right.Add(item);
                sumR += item.Value;
            }
            if (i >= x) {
                var old = (Value: nums[i - x], Index: i - x);
                if (left.Remove(old)) {
                    sumL -= old.Value;
                } else {
                    right.Remove(old);
                    sumR -= old.Value;
                }
            }
            if (left.Count > right.Count + 1) {
                item = left.Max;
                left.Remove(item);
                right.Add(item);
                sumL -= item.Value;
                sumR += item.Value;
            } else if (left.Count < right.Count) {
                item = right.Min;
                right.Remove(item);
                left.Add(item);
                sumL += item.Value;
                sumR -= item.Value;
            }
            if (i >= x - 1) {
                long mid = left.Max.Value;
                ops[i] = mid * left.Count - sumL + sumR - mid * right.Count;
            }
        }
        return ops;
    }

    public long MinOperations(int[] nums, int x, int k) {
        int n = nums.Length;
        long[] ops = GetCosts(nums, x);
        long[] pre = new long[n + 1];
        long[] cur = new long[n + 1];

        for (int j = 1; j <= k; ++j) {
            Array.Fill(cur, long.MaxValue);
            for (int i = j * x; i <= n; ++i) {
                cur[i] = Math.Min(cur[i - 1], pre[i - x] + ops[i - 1]);
            }
            (pre, cur) = (cur, pre);
        }
        return pre[n];
    }
}