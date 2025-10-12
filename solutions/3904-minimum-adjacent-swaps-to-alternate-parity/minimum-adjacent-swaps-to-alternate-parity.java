class Solution {
    public int minSwaps(int[] nums) {
        List<Integer> ones = new ArrayList<>();
        int n = nums.length;

        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 1) {
                ones.add(i);}}

        int m = 2 * ones.size();

        if (m == n) {
            return Math.min(countSwaps(ones, 0, n), countSwaps(ones, 1, n));}
        if (m == n + 1) {
            return countSwaps(ones, 0, n);}
        if (m == n - 1) {
            return countSwaps(ones, 1, n); }
        return -1; }

    private int countSwaps(List<Integer> ones, int start, int n) {
        int swaps = 0;
        
        for (int i = 0; i < ones.size(); ++i) {
            swaps += Math.abs(ones.get(i) - (start + 2 * i));}
        return swaps;}
}