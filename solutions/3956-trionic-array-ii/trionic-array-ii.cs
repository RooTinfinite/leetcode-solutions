using System;

public class Solution {
    public long MaxSumTrionic(int[] nums) {
        int n = nums.Length;
        long res = -1_000_000_000_000_000L; // -1e16

        for (int i = 1; i < n - 2; ) {
            int a = i, b = i;
            long net = nums[a];

            while (b + 1 < n && nums[b + 1] < nums[b]) {
                net += nums[++b];
            }
            if (b == a) { i++; continue; }

            int c = b;
            long left = 0, right = 0;
            long lx = long.MinValue, rx = long.MinValue;

            while (a - 1 >= 0 && nums[a - 1] < nums[a]) {
                left += nums[--a];
                lx = Math.Max(lx, left);
            }
            if (a == i) { i++; continue; }

            while (b + 1 < n && nums[b + 1] > nums[b]) {
                right += nums[++b];
                rx = Math.Max(rx, right);
            }
            if (b == c) { i++; continue; }

            res = Math.Max(res, lx + rx + net);
            i = b;
        }
        return res;
    }
}