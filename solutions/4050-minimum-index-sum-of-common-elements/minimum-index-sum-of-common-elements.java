class Solution {
    public int minimumSum(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums1.length; i++) {
            map.putIfAbsent(nums1[i], i);
        }

        int ans = Integer.MAX_VALUE;

        for (int j = 0; j < nums2.length; j++) {
            if (map.containsKey(nums2[j])) {
                ans = Math.min(ans, j + map.get(nums2[j]));
            }
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}