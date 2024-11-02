class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> ht = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int tmp = nums[i];

            if (ht.containsKey(target - tmp)) {
                return new int[] {ht.get(target - tmp), i};
            }

            ht.put(tmp, i);
        }
        
        return new int[0];
    }
}