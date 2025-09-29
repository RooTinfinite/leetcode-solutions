class Solution {
    public long maximumTotalDamage(int[] nums) {
        Arrays.sort(nums);
        List<Pair<Integer, Long>> dp = new ArrayList<>();
        long preMax = 0, ans = 0;
        int dpIdx = 0;

        for (int i = 0; i < nums.length; i++) {
            while (dpIdx < dp.size() && dp.get(dpIdx).getKey() + 2 < nums[i]) {
                preMax = Math.max(preMax, dp.get(dpIdx).getValue());
                dpIdx++;
            }

            int j = i;
            long cur = 0;
            while (j < nums.length && nums[j] == nums[i]) {
                cur += nums[j];
                j++;
            }

            ans = Math.max(ans, cur + preMax);
            dp.add(new Pair<>(nums[i], cur + preMax));
            i = j - 1;
        }
        return ans;
    }
}