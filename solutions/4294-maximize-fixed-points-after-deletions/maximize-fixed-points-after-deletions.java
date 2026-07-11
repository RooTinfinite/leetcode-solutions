class Solution {
    public int maxFixedPoints(int[] nums) {
        int n = nums.length;

        List<int[]> v = new ArrayList<>();

        // store {i - nums[i], nums[i]}
        for (int i = 0; i < n; i++) {
            if (nums[i] <= i) {
                v.add(new int[]{i - nums[i], nums[i]});
            }
        }

        if (v.isEmpty()) return 0;

        // sort by d, then by value
        Collections.sort(v, (a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });

        // LIS on values
        List<Integer> lis = new ArrayList<>();

        for (int[] p : v) {
            int val = p[1];

            int idx = Collections.binarySearch(lis, val);
            if (idx < 0) idx = -(idx + 1); // lower_bound

            if (idx == lis.size()) {
                lis.add(val);
            } else {
                lis.set(idx, val);
            }
        }

        return lis.size();
    }
}