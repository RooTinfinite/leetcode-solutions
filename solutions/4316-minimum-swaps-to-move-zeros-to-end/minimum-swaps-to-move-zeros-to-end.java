class Solution {
    public int minimumSwaps(int[] nums) {
        int nonzero = 0;
        for(int ele: nums)
        if(ele != 0)
        nonzero++;
        
        int zero = 0;
        for(int i = 0; i<nonzero; i++)
        {
            if(nums[i] == 0)
            zero++;
        }
        return zero;
    }
}