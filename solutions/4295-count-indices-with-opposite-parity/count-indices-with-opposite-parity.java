class Solution {
    public int[] countOppositeParity(int[] nums) {
        int n = nums.length;
        int odd = 0, even = 0;

        int[] result = new int[n];

        for (int i = n - 1; i >= 0; i--) {
            if ((nums[i] & 1) == 1) { // odd
                result[i] = even;
                odd++;
            } else { // even
                result[i] = odd;
                even++;
            }
        }

        return result;
    }
}