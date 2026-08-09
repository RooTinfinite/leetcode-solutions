class Solution {
    int MOD = (int)(1e09+7);
    public int minAdjacentSwaps(int[] nums, int a, int b) {
        long count1 = 0;
        long count2 = 0;
        long res = 0;
        for(int num : nums) {
            if(num < a) {
                res += (count1+count2);
            }
            else if(num >= a && num <= b) {
                res += count2;
                count1++;
            }
            else {
                count2++;
            }
        }
        return (int)(res%MOD);
    }
}