import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxEqualAdjacentPairs(int[] nums) {
        int n = nums.length;
        int basePairs = 0;
        Map<Long, Integer> pairCount = new HashMap<>();
        int maxNewPairs = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                basePairs++;
            } else {
                int u = Math.min(nums[i], nums[i + 1]);
                int v = Math.max(nums[i], nums[i + 1]);
                long key = ((long) u << 32) | (v & 0xFFFFFFFFL);

                int count = pairCount.getOrDefault(key, 0) + 1;
                pairCount.put(key, count);
                if (count > maxNewPairs) {
                    maxNewPairs = count;
                }
            }
        }

        return basePairs + maxNewPairs;
    }
}