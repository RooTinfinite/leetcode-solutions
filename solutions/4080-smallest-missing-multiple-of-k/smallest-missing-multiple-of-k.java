class Solution {
    public int missingMultiple(int[] nums, int k) {
        Set <Integer>set=new HashSet<>();
        for(int i=0; i<nums.length;i++)
        {
            set.add(nums[i]);
        }
            int value=1;
            while(set.contains(k*value))
            {
                 value++;

            }

            return value*k;
           

        
    }
}