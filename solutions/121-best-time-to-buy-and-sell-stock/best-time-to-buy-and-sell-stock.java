class Solution {
    public int maxProfit(int[] nums) {
        int minPro = Integer.MAX_VALUE;
        int maxPro = 0;
        for (int num : nums) {
            minPro = Math.min(num, minPro);
            maxPro = Math.max(maxPro, num - minPro);
        }
        return maxPro;
    }
}