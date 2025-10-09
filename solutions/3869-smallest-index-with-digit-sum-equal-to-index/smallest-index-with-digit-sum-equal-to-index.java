class Solution {
    public static int smallestIndex(int[] nums) {
        int index = -1;
        for(int i=0;i<nums.length;i++)
        {
            if(digitSum(nums[i]) == i)
            {
                index = i;
                break;
            }
        }

        return index;        
    }
    public static int digitSum(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            int digit = num % 10;
            sum += digit;
            num /= 10;
        }
        return sum;
    }
}