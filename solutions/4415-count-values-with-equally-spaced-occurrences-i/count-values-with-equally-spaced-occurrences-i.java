class Solution {
    public int countSpecialIntegers(int[] nums) {
        // Intuition: go left to right, skip values that don't occur exactly 3 times
        // then check for an equally spaced triple with increasing distance
        int n = nums.length;
        int r = 0;
        int[] freq = new int[100];
        for (int c : nums) {
            freq[c - 1]++;
        }
        for (int i = 0; i < n; i++) {
            int c = nums[i];
            if (freq[c - 1] != 3) continue;
            freq[c - 1] = -1;
            for (int distance = 1; i + (distance * 2) < n; distance++) {
                if (nums[i + distance] == c && nums[i + (distance * 2)] == c) {
                    r++;
                    break;
                }
            }
        }
        return r;
    }
}