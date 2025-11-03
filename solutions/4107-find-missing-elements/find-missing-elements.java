class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        int min = nums[0];
        int max = nums[0];
        boolean[] seen = new boolean[101];

        for (int n : nums) {
            min = Math.min(min, n);
            max = Math.max(max, n);
            seen[n] = true;
        }

        List<Integer> res = new ArrayList<>();
        for (int i = min; i <= max; i++)
            if (!seen[i])
                res.add(i);

        return res;
    }
}