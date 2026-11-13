class Solution {
    // time = O(n), space = O(k)
    public int maximumLength(int[] nums, int k) {
        int n = nums.length, res = 1;
        int[] f = new int[n + 1];
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 0);
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1] % k, y = (k - x) % k;
            if (map.containsKey(y)) f[i] = f[map.get(y)] + 1;
            else f[i] = 1;
            res = Math.max(res, f[i]);
            if (!map.containsKey(x) || f[map.get(x)] < f[i]) map.put(x, i);
        }
        return res;
    }
}