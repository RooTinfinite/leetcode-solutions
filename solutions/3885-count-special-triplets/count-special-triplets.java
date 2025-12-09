class Solution {
    final long MOD = 1_000_000_007;

    public int specialTriplets(int[] nums) {
        int n = nums.length;

        int max = Arrays.stream(nums).max().getAsInt();

        int maxSize = max * 2 + 1;

        long[] l = new long[maxSize];
        long[] r = new long[maxSize];
        for (int v : nums)
            r[v]++;

        long ans = 0;

        for (int j = 0; j < n; j++) {
            int v = nums[j];
            r[v]--;
            int target = v * 2;
            if (target < maxSize)
                ans = (ans + l[target] * r[target]) % MOD;
    
            l[v]++;
        }
        return (int) ans;
    }
}