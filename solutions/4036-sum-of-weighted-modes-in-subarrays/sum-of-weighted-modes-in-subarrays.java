class Solution {
    // time = O(nlogn), space = O(n)
    public long modeWeight(int[] nums, int k) {
        int n = nums.length;
        long res = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        TreeSet<int[]> set = new TreeSet<>((o1, o2) -> o1[0] != o2[0] ? o2[0] - o1[0] : o1[1] - o2[1]);
        for (int i = 0, j = 0; i < n; i++) {
            if (i - j + 1 > k) {
                set.remove(new int[]{map.get(nums[j]), nums[j]});
                map.put(nums[j], map.get(nums[j]) - 1);
                if (map.get(nums[j]) > 0) set.add(new int[]{map.get(nums[j]), nums[j]});
                j++;
            }
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
            set.add(new int[]{map.get(nums[i]), nums[i]});
            if (i - j + 1 == k) {
                int[] x = set.first();
                res += 1L * x[0] * x[1];
            }
        }
        return res;
    }
} 