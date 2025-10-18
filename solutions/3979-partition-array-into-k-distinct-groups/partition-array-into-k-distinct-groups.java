import java.util.*;

class Solution {
    public boolean partitionArray(int[] nums, int k) {
        int n = nums.length;
        if (n % k != 0) return false;

        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        int g = n / k;
        for (int count : map.values()) {
            if (count > g) return false;
        }

        return true;
    }
}