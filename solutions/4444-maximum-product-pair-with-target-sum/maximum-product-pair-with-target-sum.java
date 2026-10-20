class Solution {
    public int[] maxProductPair(int[] nums, int target) {
        int[] ans = {-1, -1};
        int best = Integer.MIN_VALUE;
        Map<Integer, Integer> seen = new HashMap<>();  // value -> an index holding it
        for (int i = 0; i < nums.length; i++) {
            int x = nums[i], y = target - x;
            if (x != y && seen.containsKey(y) && x * y > best) {
                best = x * y;
                ans = x > y ? new int[] {i, seen.get(y)} : new int[] {seen.get(y), i};  // larger value first
            }
            seen.put(x, i);
        }
        return ans;
    }
}