import java.util.*;

class Solution {
    public int minimumDistance(int[] nums) {
        int n = nums.length;
        Map<Integer, List<Integer>> map = new HashMap<>();

        // Step 1: Store indices for each number
        for (int i = 0; i < n; i++) {
            map.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }

        int minDistance = Integer.MAX_VALUE;

        // Step 2: Check each number’s list
        for (List<Integer> indices : map.values()) {
            if (indices.size() < 3) continue;

            // Step 3: Only check consecutive triplets
            for (int i = 0; i < indices.size() - 2; i++) {
                int first = indices.get(i);
                int third = indices.get(i + 2);
                int distance = 2 * (third - first);
                minDistance = Math.min(minDistance, distance);
            }
        }

        return minDistance == Integer.MAX_VALUE ? -1 : minDistance;
    }
}