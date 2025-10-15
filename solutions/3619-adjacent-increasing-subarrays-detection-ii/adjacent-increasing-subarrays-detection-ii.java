class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int prevIncrease = 0, curIncrease = 1;
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums.get(i) > nums.get(i - 1)) {
                curIncrease += 1;
            } else {
                prevIncrease = curIncrease;
                curIncrease = 1;
            }
            res = Math.max(res, Math.max(curIncrease / 2, Math.min(prevIncrease, curIncrease)));
        }
        return res;
    }
}