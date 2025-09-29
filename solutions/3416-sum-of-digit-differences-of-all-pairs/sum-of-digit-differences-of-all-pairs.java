class Solution {
    public long sumDigitDifferences(int[] nums) 
    {
        int n = nums.length;
        int len = Integer.toString(nums[0]).length();
        int[][] digCount = new int[10][len]; 
        
        long ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            String num = Integer.toString(nums[i]);
            for (int pos = 0; pos < num.length(); pos++)
            {
                int dig = num.charAt(pos) - '0';
                //==============================================
                int total = n - i - 1; //count of numbers ahead of num
                
                //count of numbers which are ahead of num & have same digit at position "pos" 
                int equal = digCount[dig][pos];  
                
                //count of numbers which are ahead of num & have different digit at position "pos" 
                int notEqual = total - equal;
                
                ans = ans + (long)notEqual;
                //=================================================
                digCount[dig][pos]++;                
            }
        }
        return ans;
        
    }
}