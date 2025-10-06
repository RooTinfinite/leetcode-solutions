class Solution {
    public int largestInteger(int[] nums, int k) {
        if (nums.length < k) {
            return -1;
        }

        Map<Integer, Integer> hm = new HashMap<>();

        int i = 0;
        int j = i + k - 1;

        while (j < nums.length) {
            Set<Integer> hs = new HashSet<>();
            for (int x = i; x <= j; x++) {
                hs.add(nums[x]);
            }

            for (int num : hs) {
                hm.put(num, hm.getOrDefault(num, 0) + 1);
            }
            i++;
            j++;
        }
        int max_val = -1;
        for (Map.Entry<Integer, Integer> e : hm.entrySet()) {
            if (e.getValue() == 1) {
                max_val = Math.max(max_val, e.getKey());
            }
        }

        return max_val;
    }
}