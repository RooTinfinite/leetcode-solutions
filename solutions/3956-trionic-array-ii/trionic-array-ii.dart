import 'dart:math';

class Solution {
  int maxSumTrionic(List<int> nums) {
    int n = nums.length;
    int res = -1000000000000000;
    int i = 1;

    while (i < n - 2) {
      int a = i;
      int b = i;
      int net = nums[a];

      while (b + 1 < n && nums[b + 1] < nums[b]) {
        net += nums[++b];
      }
      if (b == a) { i++; continue; }

      int c = b;
      int left = 0;
      int right = 0;
      int lx = -9223372036854775808; // Min 64-bit int
      int rx = -9223372036854775808;

      while (a - 1 >= 0 && nums[a - 1] < nums[a]) {
        left += nums[--a];
        lx = max(lx, left);
      }
      if (a == i) { i++; continue; }

      while (b + 1 < n && nums[b + 1] > nums[b]) {
        right += nums[++b];
        rx = max(rx, right);
      }
      if (b == c) { i++; continue; }

      res = max(res, lx + rx + net);
      i = b;
    }
    return res;
  }
}