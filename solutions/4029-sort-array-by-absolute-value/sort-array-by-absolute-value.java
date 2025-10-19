class Solution {
    public int[] sortByAbsoluteValue(int[] nums) {
        return Arrays.stream(nums).boxed().sorted((a,b)->Integer.compare(Math.abs(a), Math.abs(b))).mapToInt(Integer::valueOf).toArray();
    }
}